#include	"Map.hpp"

Map::Map()
{
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
//  int			ylines = 0;
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
}

std::vector<std::string> Map::parser(std::string path)
{
  std::ifstream fd(path.c_str(), std::ios::in);
  std::string tmp;

  if (fd)
    {
      std::string       str;
    //  if (checker(path) == 1)
	//throw myException("Map Error.\n");
      while (getline(fd, str))
	{
	_map.push_back(str);
//	  		_map.push_back("test");

		y++;
	}
    //  tmp = str;
    }
//  x = tmp.size();
  return _map;
}


