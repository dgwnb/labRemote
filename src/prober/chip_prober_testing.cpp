#include <stdio.h>
#include <iostream>
#include <string>

#include "HandlerChipProberTesting.h"


using namespace std;
int main(int argc, char** argv){
    // create a real controller
	std::string dev_name("/dev/ttyUSB1");
	//here the numbers correspond to GPIB adresses. 7 is to the Agilent 1 is to the keithley 2000 and 3 is to the kiethley 2401
	HandlerChipProberTesting* handle = new HandlerChipProberTesting(dev_name, 7, 1, 3);
    cout << "controller is initialized" << endl;
    handle->print_cmd();
    string input = "";
    while(true){
		cout << "Please enter commands, Q for quit" << endl;
        getline(cin, input);
	    // cout <<"You entered: " << input << endl;
        if(input[0] == 'Q' || input[0] == 'q') break;
        if(input[0] == '\n') continue;
		handle->write(input);

    }
    delete handle;

    cout << "good bye" << endl;
}
