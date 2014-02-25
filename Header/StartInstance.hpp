
#ifndef __STARTINSTANCE_HPP_
#define __STARTINSTANCE_HPP_

#include <thread>
#include "myException.hpp"

class StartInstance 
{
public:
	StartInstance();
	~StartInstance();
	void Launch();


private:
	bool isInit;

};

#endif