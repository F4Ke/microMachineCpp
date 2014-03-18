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
	// EHEHE

	MicroMachine *m1 = new MicroMachine("Monster1", 50, 50);
	MicroMachine *m2 = new MicroMachine("CouCou2", 50, 60);
	MicroMachine *m3 = new MicroMachine("Hello3", 50, 70);
	MicroMachine *m4 = new MicroMachine("Aurevoir4", 50, 80);

	machineList.insert (std::pair<int,MicroMachine * >(0,m1) );
	machineList.insert (std::pair<int,MicroMachine * >(0,m2) );
	machineList.insert (std::pair<int,MicroMachine * >(0,m3) );
	machineList.insert (std::pair<int,MicroMachine * >(0,m4) );
 	 
	// OHOHOHO


	TimeOut *tRun = new TimeOut();
// std::thread t1(tRun->startRun);
	std::thread t1 (ActThreadRun, tRun);
//	t1.join();

		while(tRun->isTimeoutRUN())
		{
           manageCycles();
		}
}

void VirtualMachine::abortCurrentAction()
{
int tmp = 1;
while (tmp < machineList.size())
	{
	machineList[pos]->abortAction();
	tmp++;
	}
isGoing = false;
}

void VirtualMachine::startToThink()
{
int tmp = 1;
while (tmp < machineList.size())
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
	// t1.join();

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
