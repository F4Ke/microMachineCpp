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
#define     pixelByCycles (2.6) // 2.6 pix par 15 ms  --- 170 par 1s DE BASE
#define     pixelAccByMsByCycle (0.5) // sur une duree
#define     pixelMoveByCycle (3) // degree


class		VirtualMachine
{
private :
    std::vector<std::string> *_map;
	std::map<int,int> result; // ID,SCORE
	std::map<int,MicroMachine * > machineList; // ID,MicroMachine
    std::string::size_type posX;
    
	OutPut *outPut;

	bool isEnded;
    bool isGoing;
	int pos;

public :

    VirtualMachine();
    ~VirtualMachine();

     void Launch(std::vector<std::string> _map);
     void load(std::vector<std::string> _map);
     void manageCycles();
	 void abortCurrentAction();
	 void startToThink();

	 void addMachineToList(MicroMachine *m );

};

#endif		// !__VIRTUALMACHINE_HPP__ //