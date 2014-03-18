#include <iostream>
#include "myException.hpp"
using namespace std;

	myException::myException(std::string msg)
	{
		this->_msg = msg;
	}

  const char* myException::what() const throw()
  {
	  return this->_msg.c_str();
  }
