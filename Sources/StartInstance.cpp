
#include "StartInstance.hpp"
#include "TimeOut.hpp"

StartInstance::StartInstance()
{
	isInit = false;
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
		}

	}
	else
	{
	std::string error = "Error Initialisation";
		throw myException(error);

	}

	}