

#include <iostream>
#include "StartInstance.hpp"

int main(void) 
{
	int onCommence = 0;

	try
	{
		std::cout << " Launching ... \n";
		StartInstance *instance = new StartInstance();
		instance->Launch();
	}
	catch (myException &ex)
	{
	   std::cout << ex.what() << std::endl;
	}


	return 0;
}