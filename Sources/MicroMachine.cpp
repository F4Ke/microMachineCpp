#include    "MicroMachine.hpp"
#include    "StartInstance.hpp"

//Constructeur + Destructeur

MicroMachine::MicroMachine(std::string name, float _posX, float _posY ) {

	posX = _posX;
	posY = _posY;
	Name = name;
	thinking = false;
    vectorDirection = 0;
}

MicroMachine::~MicroMachine() {
}

//Methodes

void    MicroMachine::setOnMap()
{
    
 
	return ;
}

void    MicroMachine::state(std::string state) {
    

	_state = state; 
}
 

void    MicroMachine::startThinking( )
{
	if (!thinking)
	{
		thinking = true;
		//std::cout << " JE think la! OH ! " << std::endl;
	}

}


void    MicroMachine::abortAction( )
{
	 
	thinking = false;
		
	//std::cout << " :( - Bye" << std::endl;
	

}

void    MicroMachine::startRotate(int deg) {
    
    if (deg > 0 && deg < 180)
        vectorDirection = deg;
    else if (deg > 180 && deg < 360)
        vectorDirection = deg;
    else if (deg == 0)
        vectorDirection = deg;
    else if (deg == 180)
        vectorDirection = deg;
}

void    MicroMachine::startMove() {
    
}
