#ifndef __WaferProb_ControllerZaberZ_H_
#define __WaferProb_ControllerZaberZ_H_

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 199309L
#endif

#include <string>

#include "za_serial.h" // Driver of Zaber
#include "ControllerBase.h"

using namespace std;

class ControllerZaberZ : public ControllerBase
{
private:
	z_port port; //port connected to Zaber
	string dn; // device name

public: // implement controller's interface
	ControllerZaberZ(const char* device_name);
	~ControllerZaberZ();

	int connect();
	int disconnect();

	string* write_with_reply(const string& cmd);

	int write(const string& cmd);

	int set_speed(int axis, float sp);

	int mv_abs(int axis, float value); // move w.r.t home-position
	int mv_rel(int axis, float value); // move w.r.t current-position
	int stop();
	int scan_x_right();
	int scan_x_left();

	// get current position
	int get_position();

	int set_home();

	const char* device_name();

	void find_max_min();

	int set_center();
public:
	// park the device: lock it so that when powered up, 
	// don't need to homed.
	int park();
	int unpark();

private:
	// convert mili-meter to number of turns/steps
	int convert_mm_to_turns(float value);
	float convert_turns_to_mm(float turns);

	inline bool check(int rc){
		// if(rc != Z_SUCCESS) throw rc;
		return (rc == Z_SUCCESS);
	}
	void poll_until_idle();
};
#endif
