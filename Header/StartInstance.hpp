
#ifndef __STARTINSTANCE_HPP_
#define __STARTINSTANCE_HPP_

#include <thread>
#include "myException.hpp"
#include "Map.hpp"
#include "Power.hpp"
#include "VirtualMachine.hpp"

class StartInstance 
{
public:
    Map *map;
    std::vector<std::string> *_map;
    
public:
	StartInstance();
	~StartInstance();
	void Launch();


private:
	bool isInit;

};

#endif