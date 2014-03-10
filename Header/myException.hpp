#ifndef __MYEXCEPTION_HPP_
#define __MYEXCEPTION_HPP_

#include <string>
#include <exception>

class myException 
{
public:
	myException(std::string s);
	virtual const char* what() const throw();

private:
	std::string _msg;
};

#endif