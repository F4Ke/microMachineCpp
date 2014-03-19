#include    "MicroMachine.hpp"
#include    "StartInstance.hpp"

//Constructeur + Destructeur

MicroMachine::MicroMachine(std::string name, float _posX, float _posY ) {

	posX = _posX;
	posY = _posY;
	Name = name;
	thinking = false;
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
 