#ifndef _Prober_Constants_H_
#define _Prober_Constants_H_


//need to change this later
//
//Note all distances in natural_units of zaber device not in mm
//Distance constants in natural_units
//Rd53a is 150 microns thick converting to natural units is 
const int wafer_thickness{1744};
const int operating_limit{62000-wafer_thickness};
//2325 is 200 microns in natural units used for hard limit
const int hard_limit{75765+2325-wafer_thickness};
const int needle_height{75765};
const int nominal_contact_height{needle_height-wafer_thickness};
//below slicing to an integer to keep things consistent as zaber can only move to integer positions
const int percent_above_contact{static_cast<int>(0.02*nominal_contact_height+nominal_contact_height)};
const int percent_below_contact{static_cast<int>(nominal_contact_height-0.02*nominal_contact_height)};



const float overdrive{0.075};

//Agilent constants in  volts or amps respectively
const float current_limit{0.7}; 
const float test_voltage{0.5};


//Keithley 2401 Constants
//In units if volts or amps respectively
const double reference_current{0.000004};
const double reference_current_range{0.000005};
const float voltage_compliance{1};

#endif

