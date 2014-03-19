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
	std::string _state;
	bool thinking;

public:
    
	MicroMachine(std::string name, float _posX, float _posY);
    ~MicroMachine();
    
    
    void    setOnMap();
    void    state(std::string);
	void   abortAction();
	void    startThinking();
	
};

#endif /* defined(__MICROMACHINE__) */

