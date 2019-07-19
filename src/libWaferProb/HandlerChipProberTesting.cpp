#include "HandlerChipProberTesting.h"
#include "Helper.h"
#include "AgilentPs.h"
#include "USBRelay.h"
#include "Keithley2000.h"
#include "Keithley24XX.h"
#include "Prober_Constants.h"


#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // for sleep()
#include <string>


//This is a handler that runs the chip_prober executable. It is based off of the code of Handler.cpp.

HandlerChipProberTesting::HandlerChipProberTesting(std::string str, unsigned int psGPIB, unsigned int ke2000GPIB, unsigned int ke2401GPIB)
	: ps(str, psGPIB), keithley_2000(str, ke2000GPIB), keithley_2401(str, ke2401GPIB)
{
	keithley_2401.sense(KeithleyMode::CURRENT);
	keithley_2401.setSource(KeithleyMode::CURRENT, reference_current_range, reference_current);
	keithley_2401.setCompl(KeithleyMode::VOLTAGE, voltage_compliance);
	keithley_2401.turnOn();
	ps.setCh(1);
	ps.turnOn();
	ps.setCh(2);
	ps.turnOn();
}

HandlerChipProberTesting::~HandlerChipProberTesting(){
	keithley_2401.turnOff();
}
void HandlerChipProberTesting::print_cmd(){
    printf("GC --> Get the current that the agilent device\n"
            "----------------------------------------------------------\n"
            // "MVC X P --> move to positive x-axis direction, continuously\n" 
            // "MVC X N --> move to negative x-axis direction, continuously\n"  
            );
}

void HandlerChipProberTesting::write(const string& cmd) {
    if(cmd.empty()){
        return;
    }
    vector<string> raw_items;
    WaferProb::tokenizeString(cmd, ' ', raw_items);

    vector<string> items;
    // convert commands to uppercase
    for(auto& item: raw_items){
        items.push_back(WaferProb::toUpper(item)); 
    }

    const string& action(items[0]);
    // Check each case..
   	if (action =="GC")
	{
		ps.setCh(1);
		std::cout<<"Analog Current is: "<<ps.getCurrent()<<'\n';
		ps.setCh(2);
		std::cout<<"Digital Current is: "<<ps.getCurrent()<<'\n';
		return;
	}
	else {
        printf("%s not supported yet!\n", action.c_str());
		return;
        // print_cmd();
    }
}

