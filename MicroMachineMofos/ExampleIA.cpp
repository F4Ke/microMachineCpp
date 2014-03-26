#include	"ExampleIA.hpp"

ExampleIA::ExampleIA(std::string _name, int _ID)
{
	this->name = _name;
	this->ID = _ID;

}

ExampleIA::~ExampleIA()
{

}

void			ExampleIA::action()
{
	/* think */
	this->actionToDo = "move";


	// ... 
	std::cout << "ia:" << this->ID << "-" << this->actionToDo <<std::endl;
}