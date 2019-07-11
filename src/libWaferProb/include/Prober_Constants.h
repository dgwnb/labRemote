#ifndef _Prober_Constants_H_
#define _Prober_Constants_H_


//need to change this later
//
//Note all distances in natural_units of zaber device not in mm
//Distance constants in natural_units
const int wafer_thickness{0};
const int operating_limit{70000-wafer_thickness};
const int hard_limit{75765-wafer_thickness};
const int overdrive{0};

//Agilent constants in obvious units
//amps
const float current_limit{0.7}; 
//volts
const float test_voltage{0.5};
//volts
const float over_voltage{2};


#endif

