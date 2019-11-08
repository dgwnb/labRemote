#include <stdio.h>

#include <string.h>
#include <vector>
#include <stdlib.h>
#include <iostream>

#include "ControllerZaberZ.h"
#include "Helper.h"
#include "Prober_Constants.h"

using namespace std;

ControllerZaberZ::ControllerZaberZ(const char* device_name):
	ControllerBase(),
	dn(device_name)
{
	port = -1;
	m_position[0] = m_position[1] = DEFAULT_BAD_XY_POS;
	m_position[2] = DEFAULT_Z_POS;
}



ControllerZaberZ::~ControllerZaberZ(){
	disconnect();
}

int ControllerZaberZ::connect(){
	if(m_is_connected) return 0;

	printf("%s:connecting to device %s\n", __FUNCTION__, dn.c_str());

	if( check(za_connect(&port, dn.c_str())) ) {
		printf("%s connected\n", dn.c_str());
		status = 0;
		m_is_connected = true;
	} else {
		printf("%s not connected\n", dn.c_str());
		status = 1;
	}
	return status;
}

int ControllerZaberZ::disconnect(){
	if (port > 0){
		park();
		za_disconnect(port);
		port = -1;
	}
	return 0;
}

int ControllerZaberZ::write(const string& cmd)
{
	if (port < 0){
		printf("%s is not open!\n", dn.c_str());
		return -1;
	}
	za_send(port, cmd.c_str());
	char reply[256] = {0};
	za_receive(port, reply, sizeof(reply));
	printf("%s -> %s\n", cmd.c_str(), reply);

	poll_until_idle();
	return 0;
}

string* ControllerZaberZ::write_with_reply(const string& cmd)
{
	if (port < 0){
		printf("%s is not open!", dn.c_str());
		return NULL;
	}
	char reply[256] = {0};
	za_send(port, cmd.c_str());
	za_receive(port, reply, sizeof(reply));
	printf("%s -> %s\n", cmd.c_str(), reply);
	string* result = new string(reply);

	poll_until_idle();
	return result;
}

int ControllerZaberZ::stop(){
	int status = write("/stop\n");
	get_position();
	return status;
}

int ControllerZaberZ::set_speed(int axis, float value)
{
	int steps = convert_mm_to_turns(value);
	char cmd[256];
	sprintf(cmd, "/1 set maxspeed %d\n", steps);
	return write(cmd);
}

int ControllerZaberZ::mv_abs(int axis, float  value){
	int steps= convert_mm_to_turns(value);
	char cmd[256];
	sprintf(cmd, "/1 move abs %d\n", steps);
	return write(cmd);
}

int ControllerZaberZ::mv_rel(int axis, float  value){
	int steps= convert_mm_to_turns(value);
	char cmd[256];
	sprintf(cmd, "/1 move rel %d\n", steps);
	return write(cmd);
}

int ControllerZaberZ::get_position()
{
	if(port < 0){
		return 1;
	}
	char cmd[256];
	sprintf(cmd, "/1 get pos\n");

	string* rpy = write_with_reply(cmd) ;
	if(rpy == NULL) return 2;

	// analyze the reply.
	struct za_reply decoded_reply;
	za_decode(&decoded_reply, const_cast<char*>(rpy->c_str()));
	//  analyze response data.
	string data(decoded_reply.response_data);
	if(strncmp(decoded_reply.response_data, "BADDATA", 7) == 0){
		m_position[2] = DEFAULT_Z_POS;
	} else {
		natural_units_z_position=(atof(data.c_str()));
		m_position[2] = (int)(convert_turns_to_mm(atof(data.c_str()))*1000) / 1000.;
	}
	return 0;
}

int ControllerZaberZ::set_home(){
	return 0;
}

int ControllerZaberZ::set_center()
{
	return 0;
}

int ControllerZaberZ::scan_x_right()
{
	return 0;
}

int ControllerZaberZ::scan_x_left()
{
	return 0;
}

int ControllerZaberZ::set_max_limit(float value, bool natural_units){
	if (natural_units){
		//Depending on whether we want natural_units or mm determines which of the functions we use
		//Below is natural_units
		char cmd[256];
	    int	int_value= static_cast<int>(value);
		//purposefully slicing to an integer to keep everything behaving properly
		sprintf(cmd, "/1 set limit.max  %d\n", int_value);
		return write(cmd);
	}
	//Below is in mm as can be seen we first convert then send
	else {
		int steps = convert_mm_to_turns(value);	
		char cmd[256];
		sprintf(cmd, "/1 set limit.max  %d\n", steps);
		return write(cmd);
	}
}

int ControllerZaberZ::park(){
	int status = write("/1 tools parking park\n");
	if(status == 0){
		printf("%s is parked\n", dn.c_str());
	}
	return status; 
}

int ControllerZaberZ::unpark()
{
	int status = write("/1 tools parking unpark\n");
	if(status == 0){
		printf("%s is unparked\n", dn.c_str());
	} else {
		printf("%s cannot unparked\n", dn.c_str());
	}
	return status;
}


int ControllerZaberZ::convert_mm_to_turns(float value){
		// To find out where this conversion rate came from look at References
	return value * 11627;
}

int ControllerZaberZ::check_position(float height_between_needle_and_wafer){
	get_position();
	//converting height between needle and wafer to natural units
	int n_to_w_nat={convert_mm_to_turns(height_between_needle_and_wafer)};
	int value{natural_units_z_position + n_to_w_nat};
	std::cout<<value<<'\n';
	if ((value<=slop_above_contact) && (value>=slop_below_contact))
	{
		std::cout<<"Check position is good! You are ready to use LC to raise wafer to needles safety in place\n";
	}
	else
	{
		std::cout<<"SOMETHING IS WRONG DO NOT RAISE WAFER CHECK TO SEE IF EXPECTED WAFER THICKNESS IS CORRECT IN Prober_Constants fix this before raising wafer\n";
	}
	return 0;
}

float ControllerZaberZ::convert_turns_to_mm(float turns){
	return turns*0.000086 ; 
}

int ControllerZaberZ::move_to_max(){
	char cmd[256];
	sprintf(cmd, "/1 move abs %d\n", operating_limit);
	return write(cmd);

}
void ControllerZaberZ::poll_until_idle(){
	char reply[256] = { 0 };
	char pos_reply[256] = { 0 };
	struct za_reply decoded_reply;
	const struct timespec ts = { 0, 100000000 }; /* 100mil nanosec = 100ms */

	/* We use za_decode() to decode this string into more manageable parts,
	 * sorting them into the fields of a za_reply struct, then we test
	 * the device_status field. Possible values for device_status are "IDLE"
	 * and "BUSY". */
	int count = 0;
	for(;;)
	{
		za_send(port, "/\n");
		za_receive(port, reply, sizeof(reply));
		za_decode(&decoded_reply, reply);

		if(strncmp(decoded_reply.device_status, "BUSY", 4) == 0) {
			nanosleep(&ts, NULL); /* If we're busy, wait then try again */
		}
		else {
			break;
		}
		
		za_send(port, "/get pos\n");
		za_receive(port, pos_reply, sizeof(pos_reply));
		printf(pos_reply); 
		printf("\n");
		if (count > 1000){break;} else{count ++;}
	}
}

void ControllerZaberZ::find_max_min()
{
	write("/1 move max\n");
	float m_zmax;
	m_zmax= get_position();
	printf("Hello: %2f\n", m_zmax);
	write("/1 move min\n");
	float m_zmin;
	m_zmin= get_position();

	printf("range of z-axis: [%.2f, %.2f]\n", m_zmin, m_zmax);
}

const char* ControllerZaberZ::device_name(){
	return dn.c_str();
}
