#include <stdio.h>
#include <iostream>
#include <string>
#include "HandlerChipProberMovement.h"
#include "HandlerChipProberTesting.h"
#include "Prober_Constants.h"

using namespace std;
int main(int argc, char* argv[] ){
	if(argv[1]!="Single"||argv[1]!="Wafer"||"Card"){
		std::cout>>"Wrong input of what probing to do:must input Single, Wafer, or Card  correspnding to a single chip, wafer, or single chip card when running this executable"
		return;
	}
	int current_chip{0};
	std::string dev_name_movement("/dev/ttyUSB0");
	HandlerChipProberMovement* handle_m = new HandlerChipProberMovement(dev_name_movement,7);
	cout << "movement controller is initialized" << '\n';
	std::string dev_name_testing("/dev/ttyUSB1");
	HandlerChipProberTesting* handle_t = new HandlerChipProberTesting(dev_name_testing,7, 1, 3);
	cout << "testing controller is initialized" << '\n';
	if (charv[1]=="Wafer"||charv[1]=="Single"){
		cout << "Please manually align needles with first chip" << '\n';
		cout << "Type Q when done" << '\n';
		handle_m->print_cmd();
		string initl_str{"LMX "};
		initl_str.append(std::to_string(operating_limit));
		initl_str.append(" 1");
		handle_m->write(initl_str);
		string input = "";
		while(true){
			cout << "Please enter commands, Q for quit" << '\n';
			if(input[0] =='Q' || input[0] == 'q') break;
			if(input[0] == '\n') continue;
			handle_m->write(input);
		}
	}
	cout <<"Manual control over. Moving to wafer automatic stepping come back in x hours where x is the amount of hours of typical probing";
	for (int i=1; i<91; i=i++){
		bool current_chip_status{1};
		error error_step{NONE};
		current_chip++;
		//Make contact now with first chip will do this by using lc command in movement
		//Is current high enough for proper contact?
		handle_m->write("MM");
		handle_m->write("LC 30");
		cout << "Starting Contact Procedure" <<'\n';
		for (int j=1; j<6; j=j++){
			double current_channel_1= handle_m->get_current(1);
			if (current_channel_1>current_contact_cutoff){
				current_chip_status=1;
				error_step=NONE;
				break;
			}
			else{
				if(charv[1]=="Wafer"){
					handle_m->write("SC");
				}
				else if(charv[1]=="Card"){
					handle_t->write("POWERCYC");
				}
			}
			current_chip_status=0;
			error_step=LDO_MODE_ERROR;
		}
		//If chip working properly move to shunt mode 
		if (current_chip_status){
			cout<<"Starting shunt mode testing";
			handle_t->write("SHUNT");
			for (int k=1; k<6; k=k++) {
				double voltage_channel_1= handle_m->get_voltage(1);
				if(voltage_channel_1<shunt_voltage_max){
					current_chip_status=1;
					error_step=NONE;
					break;
				}
				else{
					handle_t->write("POWERCYC");
				}
				current_chip_status=0;
				error_step=SHUNT_MODE_ERROR;
			}
		}
		//Put chip into LDO mode
		if (current_chip_status){
			//See if current is within limit
		}
			//send initial configs
		if (current_chip_status){
			//send the configs
		}
		//now run all of the scans
		if (current_chip_status){
			//run Register test
			//Digital scan
			//Analog scan
			//Noise Occupancy
			//treshold scan
			//
		}
		if (charv[1]=="Single"||charv[1]=="Card"){
			break;
		}
	}
	//Now analyze the date somehow to determine which tests for which chips worked
}
