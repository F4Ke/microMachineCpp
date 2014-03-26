#ifndef __EXAMPLEIA__
#define __EXAMPLEIA__

#include    <iostream>
#include    <vector>
#include    <string>
#include    <cmath>

#include    "Map.hpp"

class       ExampleIA 
{

public:
	int ID;
	std::string name;
	std::string actionToDo;

public:
    
	ExampleIA(std::string _name, int _ID);
    ~ExampleIA();
    
    
    void   action();

};

#endif /* defined(__EXAMPLEIA__) */

