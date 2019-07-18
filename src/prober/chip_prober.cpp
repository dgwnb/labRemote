#include <stdio.h>
#include <iostream>
#include <string>

#include "Handler_chip_prober_movement.h"
#include "Prober_Constants.h"
//This copies the same code as motion_controller.cpp but implements a way to talk to the agilent device as well. 
//The current below is nearly identical to// motion_controller.cpp
//some variables we need
//float incre_x{28.7998};
//float incre_y{23.6};/
//int current_chip{-1};
//int chip[90];
//


using namespace std;
int main(int argc, char** argv){
    // create a real controller
	std::string dev_name("/dev/ttyUSB1");
    Handler_chip_prober* handle = new Handler_chip_prober(dev_name, 7);
    cout << "controller is initialized" << endl;
	bool in_contact{0};
    handle->print_cmd();
    string input = "";
	string initl_str{"LMX "};
	initl_str.append(std::to_string(operating_limit));
	initl_str.append(" 1");
	//above initiliazes a operating limit z height for zaber controller. Does this before it gives user control
	handle->write(initl_str); 
    while(true){ 
		if (in_contact){
			getline(cin, input);
			input="SPC";
		}
		else{
			cout << "Please enter commands, Q for quit" << endl;
        	getline(cin, input);
	    	// cout <<"You entered: " << input << endl;
        	if(input[0] == 'Q' || input[0] == 'q') break;
        	if(input[0] == '\n') continue;
		}
		in_contact=(handle->write(input));

    }
    delete handle;

    cout << "good bye" << endl;
}
