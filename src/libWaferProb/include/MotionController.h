#ifndef __MotionController_H_
#define __MotionController_H_

/*
 * A controller uses different other controllers.
 */

#include "ControllerBase.h"
#include "ControllerZaber.h"
#include "ControllerZaberZ.h"

class MotionController : public ControllerBase{

private:

    ControllerZaber* xy_ctrl; // xy-axis station is controlled by a machine from Zaber
    ControllerZaberZ* z_ctrl;    // z-axis controlled by a machine from Zaber as well

public:
    MotionController(const char* dn_1, const char* dn_2);
    ~MotionController();

    int connect();
    int disconnect();

    int set_speed(int axis, float sp);

    int mv_abs(int axis, float value); // move w.r.t home-position
    int mv_rel(int axis, float value); // move w.r.t current-position
    int stop();

    int get_position(int axis);
    int get_position();
	int park();
	int unpark();

    int get_pos_xy();
    int get_pos_z();

    int set_home();
    int set_center();

    int write(const string&){
        // sorry I don't know which device cmd writes to...
        return 0;
    }
    int write(int axis, const string& cmd);

//	int run_cmd(const string& cmd);

    void calibrate_Z(){
        z_ctrl->find_max_min();
    }
};
#endif
