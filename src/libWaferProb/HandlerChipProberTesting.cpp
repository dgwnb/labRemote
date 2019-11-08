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
	keithley_2000.init();
	usb_relay.relay_VIN();
}

HandlerChipProberTesting::~HandlerChipProberTesting(){
	keithley_2401.turnOff();
	usb_relay.relay_VIN();
	ps.setCh(1);
	ps.turnOff();
	ps.setCh(2);
	ps.turnOff();
}
void HandlerChipProberTesting::print_cmd(){
    printf("GC --> Get the current that the agilent device\n"
			"VIN --> Switch to VIN mode with both voltage and USB relay\n"
			"VDD --> Switch to VDD mode with both voltage and USB relay\n"
			"YARR d or a --> Run digital yarr scan if d present or analog if a present\n"
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
	else if (action =="VIN")
	{
		ps.setCh(1);
		ps.turnOff();
		ps.setVoltage(VIN);
		ps.setCh(2);
		ps.turnOff();
		ps.setVoltage(VIN);
		usb_relay.relay_VIN();
		ps.setCh(1);
		ps.turnOn();
		ps.setCh(2);
		ps.turnOn();

	}
	else if (action =="VDD")
	{
		ps.setCh(1);
		ps.turnOff();
		ps.setVoltage(VDD);
		ps.setCh(2);
		ps.turnOff();
		ps.setVoltage(VDD);
		usb_relay.relay_VDD();
		ps.setCh(1);
		ps.turnOn();
		ps.setCh(2);
		ps.turnOn();
	}
	else if (action =="TEST")
	{
		std::cout<<"channel 1: "<<std::stod((keithley_2000.readChannel("1")))<<'\n';	
		std::cout<<"channel 2: "<<std::stod((keithley_2000.readChannel("2")))<<'\n';	
		std::cout<<"channel 3: "<<std::stod((keithley_2000.readChannel("3")))<<'\n';	
	}
	else if (action=="POWERCYC"){
		ps.setCh(1);
		ps.turnOff();
		ps.setCh(2);
		ps.turnOff();
		ps.setCh(1);
		ps.turnOn();
		ps.setCh(2);
		ps.turnOn();
	}
	else if (action=="YARR")
	{
		if (items.size()!=2){
			std::cout<<"Did not define what kind of yarr scan\n";
		}
		else
		{
		 if (items[1]=="D")
			{
				yarr.digital_scan();
			}
		 else if (items[1]=="A")
			{
				yarr.analog_scan();
			}
		}
	}
	else {
        printf("%s not supported yet!\n", action.c_str());
		return;
        // print_cmd();
    }
}

