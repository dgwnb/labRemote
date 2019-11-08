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
const int slop_above_contact{static_cast<int>(2325+nominal_contact_height)};
const int slop_below_contact{static_cast<int>(nominal_contact_height-2325)};



const float overdrive{0.100};

//Chip General Constants
const float current_contact_cutoff{0.4};

//Agilent constants in  volts or amps respectively
const float current_limit{0.7}; 
const float test_voltage{1.2};
const float VIN{1.7};
const float VDD{1.2};


//Keithley 2401 Constants
//In units if volts or amps respectively
const double reference_current{0.000004};
const double reference_current_range{0.000005};
const float voltage_compliance{1};


//Chip numbering
const float incre_x{28.7998};
const float incre_y{23.6};
const int calib_chip_col{1};
const int calib_chip_row{6};

#endif





