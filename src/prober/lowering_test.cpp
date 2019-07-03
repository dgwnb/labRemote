#include <stdio.h>
#include <iostream>
#include <string>

#include "Handler_agilent.h"
//This copies the same code as motion_controller.cpp but implements a way to talk to the agilent device as well. 
//The current below is nearly identical to// motion_controller.cpp

using namespace std;
int main(int argc, char** argv){
    // create a real controller
	std::string dev_name("/dev/ttyUSB0");
    Handler_agilent* handle = new Handler_agilent(dev_name, 7);
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
