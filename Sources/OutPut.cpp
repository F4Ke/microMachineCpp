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

void    OutPut::showPlayerCollision(MicroMachine *p1, MicroMachine *p2) {
    std::cout << "PLAYERCOLLISION-" << p1->ID << "-COLLISION-" << p2->ID << std::endl;
}

void    OutPut::showEndOfGame(std::map<int,int> result) {
    int x = 1;
    unsigned long tmp = result.size();
    
    while (tmp) {
        std::cout << "RESULT-" << x << ": " << result[x] << std::endl;
        x++;
        tmp--;
    }
}

// TODO appeller ces fontions la dans le moteur de la VM
