#ifndef __OUTPUT__
#define __OUTPUT__

#include    <iostream>
#include    <vector>
#include    <string>
#include    <map>
#include	"MicroMachine.hpp"
#include	"Power.hpp"

class       OutPut 
{

public:
    
	OutPut();
    ~OutPut();
  	
    void    showPlayerPostion(MicroMachine *m);
	void    showPlayerGetBonus(MicroMachine *m, Power *p);
    void    showPlayerCollision(MicroMachine *p1, MicroMachine *p2);
    void    showEndOfGame(std::map<int,int> result);
};

#endif /* defined(__OUTPUT__) */