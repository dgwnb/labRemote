#include "Handler.h"
#include "Helper.h"

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // for sleep()

Handler::Handler(){
    ctrl = new MotionController("/dev/ttyACM0", "/dev/ttyUSB1");
    ctrl->connect();
}

Handler::~Handler(){
    ctrl->disconnect();
    delete ctrl;
}

void Handler::print_cmd(){
    printf("MA X 10  --> move X-axis w.r.t home position 10 millimeter\n"
            "MR X 10 --> move X-axis w.r.t current position 10 millimeter\n"
            "SP X 10  --> set speed in x-axis direction by 10 millimeter/s\n"
            "SH --> move to HOME\n"
            "SM --> move to center\n"
            "SZC --> set needles contact with chip\n"
            "SZS --> set needles separate from chip\n"
            "SZD 10 --> set distance in z-axis in order to separate needle and chip.\n"
            "TESTX --> move x from 0 to 305 with pre-defined steps\n"
			"UP --> unparks all of the zaber devices\n"
			"PK --> parks all of the zaber devices\n"
			"ST --> stops all of the zaber devices\n"
			"GP --> gets the position of all the zaber devices\n"
            "SX --> Scan X direction\n"
            "----------------------------------------------------------\n"
            // "MVC X P --> move to positive x-axis direction, continuously\n" 
            // "MVC X N --> move to negative x-axis direction, continuously\n"  
            );
}

void Handler::write(const string& cmd) {
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
//	std::cout<<items[0];
//	std::cout<<items[1];
    // Check each case..
    if (action == "MA")
    {
        if(items.size() != 3){
            printf("argument of MA is wrong\n"
                    "MA X/Y/Z 10\n");
            return;
        }
        int axis = WaferProb::axis_number(items[1]);
        ctrl->mv_abs(axis, atof(items[2].c_str()));
    } else if (action == "MR")
    {
        if(items.size() != 3){
            printf("argument of MR is wrong\n"
                    "MR X/Y/Z 10\n");
            return;
        }
        int axis = WaferProb::axis_number(items[1]);
        ctrl->mv_rel(axis, atof(items[2].c_str()));
    } else if (action == "SH")
    {
        ctrl->set_home();
    }
	  else if (action == "ST")
	{
		ctrl->stop();
	}
	  else if (action == "GP")
	{
	    ctrl->get_position();
	}
	  else if (action == "PK")
	{
		ctrl->park();
    }
	  else if (action == "UP")
	{
	    ctrl->unpark();
	} 
      else if (action =="SX")
	{
		ctrl->scan_x_right();
	}
	 else if (action =="SB")
    {
		ctrl->scan_x_left();
	}
	  else if (action == "SM")
    {
        ctrl->set_center();
    } 
    else if (action == "SP")
    {
        if (items.size() != 3){
            printf("argument of SP is wrong\n"
                    "SP X/Y/Z 10000\n");
            return;
        }
        int axis = WaferProb::axis_number(items[1]);
        ctrl->set_speed(axis, atof(items[2].c_str()));
    }else if (action == "TEST"){
        vector<int> steps{20, 46, 73, 100, 126, 152, 179, 206, 226};
        if (items.size() != 2){
            printf("argument of TEST is wrong\n"
                    "TEST X/Y \n");
            return;
        }
        int axis = WaferProb::axis_number(items[1]);
        for(int step : steps){
            ctrl->mv_abs(axis,  step);
            sleep(10);
        }
    } else {
        printf("%s not supported yet!\n", action.c_str());
        // print_cmd();
    }
}
