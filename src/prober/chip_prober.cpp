#include <stdio.h>
#include <iostream>
#include <string>

#include "Handler_chip_prober.h"
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
	bool possible_contact=false;
    // create a real controller
	std::string dev_name("/dev/ttyUSB0");
    Handler_chip_prober* handle = new Handler_chip_prober(dev_name, 7);
    cout << "controller is initialized" << endl;
    handle->print_cmd();
    string input = "";
	string initl_str{"LMX "};
	initl_str.append(std::to_string(operating_limit));
	initl_str.append(" 1");
	//above initiliazes a operating limit z height for zaber controller. Does this before it turns on
	handle->write(initl_str); 
    while(true){ 
		cout << "Please enter commands, Q for quit" << endl;
        getline(cin, input);
		//As seen below if LC was used then possible_contanct is true and the stage always lowers to 0
		if (possible_contact){
			handle->write("UP");
			handle->write("MA Z 0");
			possible_contact=false;
			continue;
		}	
        // cout <<"You entered: " << input << endl;
        if(input[0] == 'Q' || input[0] == 'q') break;
        if(input[0] == '\n') continue;
		// if LC is typed the probecard may have made contact so next command alwayws lowers stage to 0
        if((input[0] == 'L' || input[0] == 'l')&&(input[1]=='c'||input[1]=='C')){
			std::cout<<"You are in possible contact with chip next command will always lower stage to 0\n";
			std::cout<<"If you did not end up in contact stage will lower and you can try again with a larger lc loop size\n";
			possible_contact=true;
		}
		handle->write(input);
    }
    delete handle;

    cout << "good bye" << endl;
}
