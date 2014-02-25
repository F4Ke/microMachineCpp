//
//  power.h
//  MicroMachine
//
//  Created by Luis on 25/02/2014.
//  Copyright (c) 2014 Luis. All rights reserved.
//

#ifndef __MicroMachine__power__
#define __MicroMachine__power__

#include    <iostream>

enum ePower {
    powerUP = 1,
    powerDown = 2,
};

class       power {

public:
    power();
    ~power();
    
    ePower  powerMode;
    std::string powerMap;
    std::string::size_type pos;
    
    void    findPowerOnMap(std::vector<std::string> map);
    void    setPowerOnMap(std::string::size_type pos)
};

#endif /* defined(__MicroMachine__power__) */