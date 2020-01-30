#include "HandlerChipProberMovement.h"
#include "Helper.h"
#include "AgilentPs.h"
#include "Prober_Constants.h"


#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // for sleep()
#include <string>


//This is a handler that runs the chip_prober executable. It is based off of the code of Handler.cpp.

HandlerChipProberMovement::HandlerChipProberMovement(std::string str, unsigned int num)
	: ps(str, num)
{
	ps.setCh(1);
	ps.setCurrent(current_limit);
	ps.setVoltage(0);
	ps.setCh(2);
	ps.setCurrent(current_limit);
	ps.setVoltage(0);
	//intiliazes agilent
}

HandlerChipProberMovement::~HandlerChipProberMovement(){
	ps.setCh(1);
	ps.turnOff();
	ps.setCh(2);
}

double HandlerChipProberMovement::get_current(int channel){
	ps.setCh(channel);
	return stod(ps.getCurrent());
}

double HandlerChipProberMovement::get_voltage(int channel){
	ps.setCh(channel);
	return stod(ps.getVoltage());
}

void HandlerChipProberMovement::print_cmd(){
    printf("MA X 10  --> move X-axis w.r.t home position 10 millimeter\n"
            "MR X 10 --> move X-axis w.r.t current position 10 millimeter\n"
            "SP X 10  --> set speed in x-axis direction by 10 millimeter/s\n"
            "SH --> move to HOME\n"
            "SM --> move to center\n"
            "TEST X --> move x from 0 to 305 with pre-defined steps\n"
			"UP --> unparks all of the zaber devices\n"
			"PK --> parks all of the zaber devices\n"
			"ST --> stops all of the zaber devices\n"
			"GP --> gets the position of all the zaber devices\n"
            "SX --> Scan X direction to the right\n"
			"SB --> Scan the X direction to the left\n"
			"MM --> Move to the maximum position used in order to get close to chip \n"
			"LC x --> Lower to chip till in contact or until z controller raised x*10 microns \n"
			"LMX 10 X--> Set the maximum limit to 10 if natural units desired let x=1 if mm let x=0 do not touch this unless absolutely necessary!!!!!!\n"
			"CP x-->check position where distance from needles to wafer is x\n"
			"SPC --> Seperate needles from chip will automaticaly do this as the next command after feeling contact\n"
			"GC --> Get the current that the agilent device sees\n"
			"SC --> Scrub the chip only do this when in contact!Will scrub pads to allow for better contact\n"
			"GTC i j -->Go to the chip that is in the x position of i and the y position of j\n"
			"CBC i j --> Calibrate chip 1-6 aka chip 1 which is at x position of i and y position of j do this before running GTC\n"
			"LW --> Put chuck into load wafer position this will allow easier loading of wafer without having to guess where to move\n"
            "----------------------------------------------------------\n"
            // "MVC X P --> move to positive x-axis direction, continuously\n" 
            // "MVC X N --> move to negative x-axis direction, continuously\n"  
            );
}


bool HandlerChipProberMovement::write(const string& cmd) {
    if(cmd.empty()){
        return 0;
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
    if (action == "MA")
    {
        if(items.size() != 3){
            printf("argument of MA is wrong\n"
                    "MA X/Y/Z 10\n");
            return 0;
        }
        int axis = WaferProb::axis_number(items[1]);
        ctrl->mv_abs(axis, atof(items[2].c_str()));
		return 0;
    } else if (action == "MR")
    {
        if(items.size() != 3){
            printf("argument of MR is wrong\n"
                    "MR X/Y/Z 10\n");
            return 0;
        }
        int axis = WaferProb::axis_number(items[1]);
        ctrl->mv_rel(axis, atof(items[2].c_str()));
		return 0;
    } else if (action == "SH")
    {
        ctrl->set_home();
		return 0;
    }
	  else if (action == "GTC")
	{
		if(items.size()!=3){
			std::cout<<"Argument of GTC is wrong did not provide both an x and y coordinate\n";
			return 0;
			}
		float chip_col= atof(items[1].c_str());
		float chip_row= atof(items[2].c_str());
		float chip_x_pos=(((calib_chip_col-chip_col)*incre_x)+chip_1_x_pos);
		float chip_y_pos=(((calib_chip_row-chip_row)*incre_y)+chip_1_y_pos);
		ctrl->mv_abs(0, chip_x_pos);
		ctrl->mv_abs(1, chip_y_pos);
		return 0;
	}
	  else if (action == "CBC")
	{
	  	if(items.size()!=3){
			std::cout<<"Arguement of CBC is wrong expects an x and a y value\n";
			return 0;
			}
		chip_1_x_pos=(atof(items[1].c_str()));
		chip_1_y_pos=(atof(items[1].c_str()));
		return 0;
	}
	  else if (action == "ST")
	{
		ctrl->stop();
		return 0;
	}
	  else if (action == "GP")
	{
	    ctrl->get_position();
		return 0;
	}
	  else if (action == "PK")
	{
		ctrl->park();
		return 0;
    }
	  else if (action == "LW")
	{
		ctrl->mv_abs(0, 152.50);
	  	ctrl->mv_abs(1, 273.50);
		return 0;
	}
	  else if (action == "MM")
	{	  
		ctrl->move_to_max();
		return 0;
	}
	  else if (action =="GC")
	{
		ps.setCh(1);
		std::cout<<"Chip current is: "<<ps.getCurrent()<<'\n';
		ps.setCh(2);
		std::cout<<"Aux current  is: "<<ps.getCurrent()<<'\n';
		return 0;
	}
	  else if (action == "SPC")
	{
		ctrl->unpark();
		ctrl->move_to_max();
		return 0;
	}
 	  else if (action == "CP")
	{
	 	if (items.size() !=2){
			std::cout<<"Did not give an arguement for the distance between needles and wafer\n";
			return 0;
		}
		else
		{
			ctrl->check_position(atof(items[1].c_str()));
			return 0;
		}

	}
	  else if (action == "UP")
	{
	    ctrl->unpark();
		return 0;
	} 
      else if (action =="SX")
	{
		ctrl->scan_x_right();
		return 0;
	}
	 else if (action =="SB")
    {
		ctrl->scan_x_left();
		return 0;
	}
	  else if (action == "SM")
    {
        ctrl->set_center();
		return 0;
    }
	  else if (action == "SC")
	{
		ps.turnOff();
		ctrl->set_max_limit(hard_limit,1);
		ctrl->set_speed(1, 0.2);
		ctrl->set_speed(2, 0.2);
		ctrl->unpark();
		ctrl->mv_rel(1, -0.01);
		ctrl->mv_rel(2, -0.2);
		ctrl->mv_rel(1, 0.01);
		ctrl->mv_rel(2, 0.2);
		ctrl->set_max_limit(operating_limit, 1);
		ctrl->park();
		ps.turnOn();
		return 1;
	}

	  else if (action == "LMX")
	{
		if (items.size() !=3){
			std::cout<<"did not give an arguement of where to set limit\n";
			return 0;
		}
		 float value= atof(items[1].c_str());
		 bool natural_units = atof(items[2].c_str());
		 ctrl->set_max_limit(value,natural_units);
		 return 0;
	}
    else if (action == "SP")
    {
        if (items.size() != 3){
            printf("argument of SP is wrong\n"
                    "SP X/Y/Z 10000\n");
            return 0;
        }
        int axis = WaferProb::axis_number(items[1]);
        ctrl->set_speed(axis, atof(items[2].c_str()));
		return 0;
    }else if (action == "TEST"){
        vector<int> steps{20, 46, 73, 100, 126, 152, 179, 206, 226};
        if (items.size() != 2){
            printf("argument of TEST is wrong\n"
                    "TEST X/Y \n");
            return 0;
        }
        int axis = WaferProb::axis_number(items[1]);
        for(int step : steps){
            ctrl->mv_abs(axis,  step);
            sleep(10);
        }
		return 0;
    }else if (action =="LC"){
		if (items.size()!=2){
			std::cout << "Did not define how many steps of 10 microns desired\n";
			return 0;
		}
		else{
			ctrl->set_max_limit(hard_limit, 1);
			//Here 1 above means that I want the limit to be set in natural units since constants defined in natural units
		 	int loops= atof(items[1].c_str());
			ps.setCh(1);
			ps.setVoltage(test_voltage);
			ps.setCurrent(current_limit);
			ps.setCh(2);
			ps.setVoltage(test_voltage);
			ps.setCurrent(current_limit);
			for(int i=0;i<loops;i++){
				ps.setCh(1);
				ps.turnOn();
				double current_channel_1= std::stod(ps.getCurrent());
				ps.turnOff();
				ps.setCh(2);
				ps.turnOn();
				double current_channel_2= std::stod(ps.getCurrent());
				ps.turnOff();
				std::cout<<"Analog Current is: "<<current_channel_1<<'\n';
				std::cout<<"Digital Current is: "<<current_channel_2<<'\n';
				if (current_channel_1>0.01 || current_channel_2>0.1)
				{
					std::cout<<"You are in contact next command will lower stage no matter what you type\n";
					std::cout<<"Just press enter to lower stage then can put in new commands\n";
					ctrl->mv_rel(2 ,overdrive);
					ctrl->park();
					ctrl->set_max_limit(operating_limit, 1);
					//Here 2 is the z axis and overdrive is the distance wanted to overdrive needles into proper contanct
					return 1;
				}
				ctrl->mv_rel(2,0.01);
				//Stod converts a string to a double	
			}
			ctrl->park();
			ctrl->set_max_limit(operating_limit, 1);
			return 0;
			// Again here 1 means the same thing as above
		}
	}else {
        printf("%s not supported yet!\n", action.c_str());
		return 0;
        // print_cmd();
    }
}

