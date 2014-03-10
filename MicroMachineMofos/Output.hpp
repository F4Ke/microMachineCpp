#ifndef __OUTPUT__
#define __OUTPUT__

#include    <iostream>
#include    <vector>
#include    <string>
#include	"MicroMachine.hpp"
#include	"Power.hpp"

class       OutPut 
{

public:
    
	OutPut();
    ~OutPut();
  	void showPlayerPostion(MicroMachine *m);
	void showPlayerGetBonus(MicroMachine *m, Power *p);


};

#endif /* defined(__OUTPUT__) */