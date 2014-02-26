//
//  Power.hpp
//  MicroMachine
//
//  Created by Luis on 25/02/2014.
//  Copyright (c) 2014 Luis. All rights reserved.
//

#ifndef __MicroMachine__Power__
#define __MicroMachine__Power__

#include    <iostream>
#include    <vector>
#include    <string>
#include    <cstdlib>
#include    <ctime>
#include    "Map.hpp"



enum ePower {
    powerUp = 1,
    powerDown = 2
};

class       Power {

public:
    Power();
    ~Power();
    
    ePower  powerMode;
    std::string powerMap;
    std::string::size_type pos;
    
    Map     *findPowerOnMap(Map *map);
   // std::string   *setPowerOnMap(std::string::size_type pos, std::string str);
    void   setPowerOnMap(std::string::size_type pos, std::string str,std::string &tmp);


};

#endif /* defined(__MicroMachine__Power__) */