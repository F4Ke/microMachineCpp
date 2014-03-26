#ifndef __MICROMACHINE__
#define __MICROMACHINE__

#include    <iostream>
#include    <vector>
#include    <string>
#include <cmath>

#include    "Map.hpp"

enum eDirection {
    UP = 1,
    RIGHT = 2,
	RIGHTUP = 3,
	RIGHTDOWN = 4,
	LEFT = 5,
	LEFTUP = 6,
	LEFTDOWN = 7,
	DOWN = 8
};

enum eGetDirct
{
	RIGHTDIR = 1,
	LEFTDIR = 2
};


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
	float ratioDegree; // 3.14159/180;
	eDirection direction;
	eGetDirct getDirect;
public:
    
	MicroMachine(std::string name, float _posX, float _posY);
    ~MicroMachine();
    
    
    void    setOnMap();
    void    state(std::string);
	void    abortAction();
	void    startThinking();
    void    startRotate(int deg, eGetDirct getDirect);
    void    Move();
	
};

#endif /* defined(__MICROMACHINE__) */

