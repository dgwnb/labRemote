#ifndef __WaferProb_HandlerChipProberTesting_H_
#define __WaferProb_HandlerChipProberTesting_H_

/*
 * A wrapper of all controls.
 * define our own commands to control the station.
 */
#include "AgilentPs.h"
#include "USBRelay.h"
#include "Keithley2000.h"
#include "Keithley24XX.h"

#include <string>
#include <vector>


class HandlerChipProberTesting {
private:
AgilentPs ps;
USBRelay usb_relay;
Keithley2000 keithley_2000;
Keithley24XX keithley_2401;


public:
    HandlerChipProberTesting(std::string str,unsigned int psGPIB, unsigned int ke2000GPIB, unsigned int ke2401GPIB);
    virtual ~HandlerChipProberTesting();
    void write(const std::string& cmd);
	void print_cmd();
};

#endif
