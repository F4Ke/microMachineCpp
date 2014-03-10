#include	"VirtualMachine.hpp"

VirtualMachine::VirtualMachine()
{
   	isEnded = false;
	isGoing = false;
	pos = 1;

}

VirtualMachine::~VirtualMachine()
{
}

void ActThreadRun(TimeOut *tRun)
{
	tRun->startRun();
}

void ActThreadThink(TimeOut *tThink)
{
	tThink->startThink();
}

void VirtualMachine::Launch()
{
	TimeOut *tRun = new TimeOut();
// std::thread t1(tRun->startRun);
	std::thread t1 (ActThreadRun, tRun);
	t1.join();

		while(tRun->isTimeoutRUN())
		{
           manageCycles();
		}
}

void VirtualMachine::abortCurrentAction()
{
int tmp = 1;
while (tmp < pos)
	{
	machineList[pos]->abortAction();
	tmp++;
	}
}

void VirtualMachine::startToThink()
{
int tmp = 1;
while (tmp < pos)
	{
	machineList[pos]->startThinking();
	tmp++;
	}

isGoing = true;
}

void VirtualMachine::manageCycles()
{
	TimeOut *tThink = new TimeOut();
// std::thread t1(tRun->startRun);
	std::thread t1 (ActThreadThink, tThink);
	t1.join();

	while(!isEnded)
		{
			while (tThink->isTimeoutTHINK())
			{
				if (!isGoing)
					startToThink();
				
			}  
			abortCurrentAction();
		}
}

void VirtualMachine::addMachineToList(MicroMachine *m)
{
	 machineList[pos] = m;
	 pos++;
}
