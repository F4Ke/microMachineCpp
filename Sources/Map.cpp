#include	"Map.hpp"

Map::Map()
{
    _map = new std::vector<std::string>();
  x = 0;
  y = 0;
}

Map::~Map()
{
}

int			Map::checker(std::string path)
{
  std::ifstream		fd(path.c_str(), std::ios::in);
  std::string		tmp;
  int			xlines = 0;
  int			xcheck = 0;

  if (fd)
    {
      std::string	str;
      getline(fd, str);
      xcheck = str.size();
      while (getline(fd, str))
	{
	  tmp = str;
	  xlines = tmp.size();
	  if (xcheck != xlines)
	    return (1);
	  xcheck = xlines;
	}
      return (0);
    }
    return (0);
}

std::vector<std::string> *Map::parser(std::string path)
{
  std::ifstream fd(path.c_str(), std::ios::in);
  std::string tmp;

  if (fd)
    {
      std::string       str;
      while (getline(fd, str))
	{
        _map->push_back(str);
		y++;
	}
    }
  return _map;
}


void        Map::seeMap() {
    std::vector<std::string>::iterator iter = _map->begin();
	int line = 0;
    while (iter != _map->end()) {
          std::cout << line << ": " << *iter << std::endl;

        iter++;
		line++;
    }
}

std::vector<std::string>::iterator        Map::setLine(int i, std::string *tmp) {
     std::vector<std::string>::iterator deleted;   
	this->_map->insert(_map->begin() + i, *tmp);
   deleted = this->_map->erase(_map->begin() + i + 1);

	return deleted;
}