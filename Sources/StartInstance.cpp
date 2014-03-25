#include "StartInstance.hpp"
#include "TimeOut.hpp"


StartInstance::StartInstance()
{
	isInit = false;
	map = new Map();
    _map = new std::vector<std::string>();
	_map = map->parser("/Users/Luis/Documents/Dev/Depot/microMachineCpp/MAP/map1");
    //_map = map->parser("MAP/map1.txt");

	map->setMap(_map);
}

StartInstance::~StartInstance()
{
}



void StartInstance::Launch()
{
	isInit = true;
	VirtualMachine *vm = new VirtualMachine();


	if (isInit)
	{
		  Power *p = new Power();

            std::cout << "V1" << std::endl;
			map->seeMap();
            std::cout << "-----------" << std::endl;
            map = p->findPowerOnMap(map);
            std::cout << "V2" << std::endl;
            map->seeMap();
			std::cout << "-----------" << std::endl;
	
			
			vm->Launch(*map->getMap());

	}
	else
	{
	std::string error = "Error Initialisation";
		throw myException(error);

	}
}