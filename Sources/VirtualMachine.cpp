#include	"VirtualMachine.hpp"

VirtualMachine::VirtualMachine()
{
   	isEnded = false;
	isGoing = false;
	pos = 0;

	numberID = 0;

}

VirtualMachine::~VirtualMachine()
{ 
}  

void    ActThreadRun(TimeOut *tRun)
{
	tRun->startRun();
	//std::chrono::milliseconds dura( 2000 ); // 
  //  std::this_thread::sleep_for( dura );//this makes this thread sleep for 2s

}

void    ActThreadThink(TimeOut *tThink)
{
	tThink->startThink();
}

void    VirtualMachine::load(std::vector<std::string> _map) {

    std::vector<std::string>::iterator iter = _map.begin();
    MicroMachine *m1;
    MicroMachine *m2;
    MicroMachine *m3;
    MicroMachine *m4;
    int y = 0;
    while (iter != _map.end()) {
        try {
            posX = iter->find('A');
            m1 = new MicroMachine("Monster1", (((int)posX * pixelByBoxes) - (pixelByBoxes / 2)) , (y * pixelByBoxes) - (pixelByBoxes / 2));
            m2 = new MicroMachine("Coucou2", (((int)posX + 1) * pixelByBoxes) - (pixelByBoxes / 2) , (y * pixelByBoxes) - (pixelByBoxes / 2));
            m3 = new MicroMachine("Hello3", (((int)posX + 2) * pixelByBoxes) - (pixelByBoxes / 2), (y * pixelByBoxes) - (pixelByBoxes / 2));
            m4 = new MicroMachine("Aurevoir4", (((int)posX + 3) * pixelByBoxes) - (pixelByBoxes /2), (y * pixelByBoxes) - (pixelByBoxes / 2));
        }
        catch (myException ex) {
        }
        
        iter++;
        y++;
    }
	m1->ID = 1;
	m2->ID = 2;
	m3->ID = 3;
	m4->ID = 4;

	m1->speed = pixelAccByMsByCycle;
	m2->speed = pixelAccByMsByCycle;
	m3->speed = pixelAccByMsByCycle;
	m4->speed = pixelAccByMsByCycle;
	
	m1->vectorDirection = 0;
	m2->vectorDirection = 0;
	m3->vectorDirection = 0;
	m4->vectorDirection = 0;

	machineList.insert (std::pair<int,MicroMachine * >(0,m1) );
	machineList.insert (std::pair<int,MicroMachine * >(1,m2) );
	machineList.insert (std::pair<int,MicroMachine * >(2,m3) );
	machineList.insert (std::pair<int,MicroMachine * >(3,m4) );

	// 
	std::cout << "Champs loaded ! \n\n";
}

void    VirtualMachine::Launch(std::vector<std::string> _map)
{
    load(_map);
    

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
int tmp = 0;
while (tmp < machineList.size())
	{
	machineList[tmp]->abortAction();
	tmp++;
	}
isGoing = false;
}

void VirtualMachine::startToThink()
{
int tmp = 0;
while (tmp < machineList.size())
	{
	machineList[tmp]->startThinking();
	tmp++;
	}

isGoing = true;
}

void VirtualMachine::setOutPut()
{
	this->outPut->showPlayerPostion(machineList[0]);
	this->outPut->showPlayerPostion(machineList[1]);
	this->outPut->showPlayerPostion(machineList[2]);
	this->outPut->showPlayerPostion(machineList[3]);
}

void VirtualMachine::manageCycles()
{


	this->cycle = 1;
	while(!isEnded)
		{
			std::cout << "Cycle n" << cycle << std::endl;
			/*	TimeOut *tThink = new TimeOut();
 		std::thread t1 (ActThreadThink, tThink);*/
			// 
//			while (tThink->isTimeoutTHINK())
			while (true)
			{
				
				if (!isGoing)
					startToThink();
			//	t1.join();
				//
				std::chrono::milliseconds dura( 15 );
				//std::chrono::milliseconds dura( 1000 ); // for debug

				std::this_thread::sleep_for( dura );//this makes this thread sleep for 15ms
				break;

				//
			}  
			abortCurrentAction();
			cycle++;
			setOutPut();
		}
}

void VirtualMachine::addMachineToList(MicroMachine *m)
{
	 machineList[pos] = m;
	 pos++;
}
