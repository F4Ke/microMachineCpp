#include    "OutPut.hpp"
 
//Constructeur + Destructeur

OutPut::OutPut() {
}

OutPut::~OutPut() {
}

//Methodes

void    OutPut::showPlayerPostion(MicroMachine *m)
{
	std::cout << "PLAYERPOSTION-" << m->ID << "-X-" << m->posX << "-Y-" << 
		m->posY << "-Direction-" << m->vectorDirection << std::endl;
}

void    OutPut::showPlayerGetBonus(MicroMachine *m, Power *p)
{
	std::cout << "PLAYERGETBONUS-" << m->ID << "-POWER-" << p->powerMode << std::endl;
}

// TODO appeller ces fontions la dans le moteur de la VM