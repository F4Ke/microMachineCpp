#ifndef __MICROMACHINE__
#define __MICROMACHINE__

#include    <iostream>
#include    <vector>
#include    <string>

#include    "Map.hpp"


class       MicroMachine 
{

public:
	int ID;
	float posX;
	float posY;
	float speed;
	float vectorDirection; // 0 -> 360 // degree dicrection 
	std::string Name;


public:
    
	MicroMachine();
    ~MicroMachine();
    
    
    void    setOnMap();
    void    state();
	void   abortAction() {}
	void    startThinking() {}

};

#endif /* defined(__MICROMACHINE__) */

