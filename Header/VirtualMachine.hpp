#ifndef		__VIRTUALMACHINE_HPP__
#define     __VIRTUALMACHINE_HPP__

#include	<string>
#include	<iostream>
#include	<vector>
#include	<fstream>
#include    <iterator>
#include    <map>
#include	<thread>
#include    "myException.hpp"
#include    "OutPut.hpp"
#include    "TimeOut.hpp"
#include    "MicroMachine.hpp"

#define     pixelByBoxes (128)

class		VirtualMachine
{
private :
    std::vector<std::string> *_map; // a voir
	std::map<int,int> result; // ID,SCORE
	std::map<int,MicroMachine * > machineList; // ID,MicroMachine

	OutPut *outPut;

	bool isEnded;
		bool isGoing;
	int pos;

public :

    VirtualMachine();
    ~VirtualMachine();

	 void Launch();
	 void manageCycles();
	 void abortCurrentAction();
	 void startToThink();

	 void addMachineToList(MicroMachine *m );
};

#endif		// !__VIRTUALMACHINE_HPP__ //