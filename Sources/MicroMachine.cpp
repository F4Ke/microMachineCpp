#include    "MicroMachine.hpp"
#include    "StartInstance.hpp"

//Constructeur + Destructeur

MicroMachine::MicroMachine(std::string name, float _posX, float _posY) {

	posX = _posX;
	posY = _posY;
	Name = name;
	thinking = false;
    vectorDirection = 0;
	this->ratioDegree = 3.14159/180;
	this->direction = UP;
	this->action = "move";
	this->ia = new ExampleIA("MonIA", numberID);
	numberID++;
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

		// listen to output IA
		// -- example : "ia:ID-Action"
		this->ia->action();

		if (action == "move") // move on standar output
		{
			Move();
 		}
		else if (action == "left") //
		{
			startRotate(pixelMoveByCycle, LEFTDIR); // 2 == left
		}
	}

}


void    MicroMachine::abortAction( )
{
	 
	thinking = false;
		
	//std::cout << " :( - Bye" << std::endl;
	

}

void    MicroMachine::startRotate(int deg, eGetDirct getDirect) {
    
	if (getDirect == LEFTDIR)
	{
		if (vectorDirection >= 0 && vectorDirection <= 357)
			vectorDirection += deg;				
		if (vectorDirection == 358)
			vectorDirection = 1;
		if (vectorDirection == 359)
			vectorDirection = 2;
		if (vectorDirection == 360)
			vectorDirection = 0;
	}
	else if (getDirect == RIGHTDIR)
	{
		if (vectorDirection >= 357 && vectorDirection <= 3)
			vectorDirection -= deg;				
		if (vectorDirection == 2)
			vectorDirection = 359;
		if (vectorDirection == 1)
			vectorDirection = 358;
		if (vectorDirection == 0)
			vectorDirection = 360;
	}

    if (deg > 0 && deg < 180) 
	{
		if (deg < 90)
			this->direction = LEFTUP;
		else if (deg > 90)	
			this->direction = LEFTDOWN;
		else
			this->direction = LEFT;
	}
	else if (deg > 180 && deg < 360)
	{
		if (deg < 270)
			this->direction = RIGHTDOWN;
		else if (deg > 90)	
			this->direction = RIGHTUP;
		else
			this->direction = RIGHT;
	}
	else if (deg == 0)
		this->direction = UP;
    else if (deg == 180)
		this->direction = DOWN;
	 

}

void    MicroMachine::Move() 
{
	float tmpDirection = std::cos(vectorDirection * this->ratioDegree);
	if (direction == UP)
	{
		this->posY += speed;
	}
	else if (direction == DOWN)
	{
		this->posY -= speed;
	}
	else if (direction == LEFT)
	{
		this->posX -= speed;
	}
	 
	else if (direction == RIGHT)
	{
		this->posX += speed;
	}
	else if (direction == RIGHTUP)
	{
		this->posY += speed - tmpDirection;
		this->posX += tmpDirection;
	}
	else if (direction == RIGHTDOWN)
	{
		this->posY -= (speed - tmpDirection);
		this->posX += tmpDirection;
	}
	else if (direction == LEFTUP)
	{
		this->posY += speed - tmpDirection;
		this->posX -= tmpDirection;
	}
	else if (direction == LEFTDOWN)
	{
		this->posY -= (speed - tmpDirection);
		this->posX -= tmpDirection;
	}
}