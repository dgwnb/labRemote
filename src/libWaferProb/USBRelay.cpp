#include<iostream>
#include<cstdlib>

#include"USBRelay.h"

USBRelay::USBRelay()
{
}

USBRelay::~USBRelay()
{
}

void USBRelay::relay_VIN()
{
	std::system("/home/amolnar/usb-relay-hid/commandline/build/hidusb-relay-cmd on 1");
	std::system("/home/amolnar/usb-relay-hid/commandline/build/hidusb-relay-cmd on 2");

}
void USBRelay::relay_VDD()
{
	std::system("/home/amolnar/usb-relay-hid/commandline/build/hidusb-relay-cmd off 1");
	std::system("/home/amolnar/usb-relay-hid/commandline/build/hidusb-relay-cmd off 2");
}
