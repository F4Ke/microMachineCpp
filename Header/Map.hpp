#ifndef		__MAP_HH__
# define       	__MAP_HH__

#include	<string>
#include	<iostream>
#include	<vector>
#include	<fstream>
#include    "myException.hpp"
//class		MyGame;

class		Map
{
private :
  std::vector<std::string> *_map;
  int x;
  int y;

public :

  Map();
  ~Map();

  std::vector<std::string> *parser(std::string path);
  int	checker(std::string path);

  void setMap(std::vector<std::string> *map) {_map = map;}

  int getX() { return x; }
  int getY() { return y; }

  std::vector<std::string> *getMap() { return _map; } // A MEDITER

};

#endif		// !__MAP_HH__
