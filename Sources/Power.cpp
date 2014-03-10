//
//  Power.cpp
//  MicroMachine
//
//  Created by Luis on 25/02/2014.
//  Copyright (c) 2014 Luis. All rights reserved.
//

#include    "Power.hpp"
#include    "StartInstance.hpp"

//Constructeur + Destructeur

Power::Power() {
}

Power::~Power() {
}

//Methodes

void    Power::setPowerOnMap(std::string::size_type pos, std::string str, std::string &tmp) {
    
    std::string *finalReturn;
    
    std::srand(std::time(0));
    int powerRand = (std::rand() % 2) + 1;
    powerMode = (ePower)powerRand;

    if (powerMode == powerUp)
        str.replace(pos, 1, "U");
    else if (powerMode == powerDown)
        str.replace(pos, 1, "D");
    
    finalReturn = &str;
	tmp = str;
  //  return(finalReturn);
	return ;
}

Map    *Power::findPowerOnMap(Map *map) {
    
    std::vector<std::string> *tmpMap = map->getMap();
    std::vector<std::string>::iterator iter = tmpMap->begin();

    int i = 0;
    
    while (iter != tmpMap->end()) {
        try {
        pos = iter->find('X');
            }
        catch (myException ex) {
        pos = std::string::npos;
             }
        if (pos != std::string::npos && pos < 20) {
			std::string tmp;
			setPowerOnMap(pos, *iter, tmp);
           // tmp = setPowerOnMap(pos, *iter);
            iter = map->setLine(i, &tmp);
        //map->setLine(i, tmp);
		}
		else
		  iter++;
        i++;
    }
    map->setMap(tmpMap);
    return (map);
}