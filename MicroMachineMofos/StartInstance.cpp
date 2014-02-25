
#include "StartInstance.hpp"
#include "TimeOut.hpp"

Map *map = NULL;
std::vector<std::string> _map;

StartInstance::StartInstance()
{
	isInit = false;
	_map = map->parser("MAP/map1");
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
	TimeOut *tRun = new TimeOut();
//	std::thread t1(tRun->startRun);
	std::thread t1 (ActThreadRun, tRun);
	t1.join();
	tRun->startRun();

	if (isInit)
	{
		while(tRun->isTimeoutRUN())
		{
			// affiche map - calle un bonnus ou deux - reaffiche
		}

	}
	else
	{
	std::string error = "Error Initialisation";
		throw myException(error);

	}

	}