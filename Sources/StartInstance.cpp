
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

void ActThreadRun(TimeOut *tRun)
{
	tRun->startRun();
}

void StartInstance::Launch()
{
	isInit = true;
    Power *p = new Power();
	TimeOut *tRun = new TimeOut();
//	std::thread t1(tRun->startRun);
	std::thread t1 (ActThreadRun, tRun);
	t1.join();
	//tRun->startRun();

	if (isInit)
	{
		while(tRun->isTimeoutRUN())
		{
            std::cout << "V1" << std::endl;
			map->seeMap();
            std::cout << "-----------" << std::endl;
            map = p->findPowerOnMap(map);
            std::cout << "V2" << std::endl;
            map->seeMap();
			std::cout << "-----------" << std::endl;
			while (true);
		}

	}
	else
	{
	std::string error = "Error Initialisation";
		throw myException(error);

	}

	}