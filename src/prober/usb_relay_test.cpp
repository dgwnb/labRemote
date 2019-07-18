#include<iostream>
#include<cstdlib>

#include"USBRelay.h"

int main()
{
	
	USBRelay usb;
	usb.relay_VDD();
	usb.relay_VIN();
	return 0;



}
