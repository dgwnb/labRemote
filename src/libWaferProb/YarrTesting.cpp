#include <iostream>
#include <cstdlib>

#include "YarrTesting.h"

YarrTesting::YarrTesting()
{
	std::system("/home/amolnar/Yarr/src/bin/test ");
}

YarrTesting::~YarrTesting()
{
}

void YarrTesting::digital_scan()
{
	std::system("/home/amolnar/Yarr/src/bin/scanConsole -r /home/amolnar/Yarr/src/configs/controller/specCfg.json -c /home/amolnar/Yarr/src/configs/connectivity/example_rd53a_setup.json -s /home/amolnar/Yarr/src/configs/scans/rd53a/std_digitalscan.json -p");
}

void YarrTesting::analog_scan()
{
	std::system("/home/amolnar/Yarr/src/bin/scanConsole -r /home/amolnar/Yarr/src/configs/controller/specCfg.json -c /home/amolnar/Yarr/src/configs/connectivity/example_rd53a_setup.json -s /home/amolnar/Yarr/src/configs/scans/rd53a/std_analogscan.json -p");
}





