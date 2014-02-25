//
//  power.cpp
//  MicroMachine
//
//  Created by Luis on 25/02/2014.
//  Copyright (c) 2014 Luis. All rights reserved.
//

#include "power.h"

//Constructeur + Destructeur

power::power() {
}

power::~power() {
}

//Methodes

void    power::setPowerOnMap(std::string::sizeof pos, int i) {
    
    std::srand(std::time(0));
    int powerRand = (std::rand() % 2) + 1;
    powerMode = (ePower)powerRand;
    
    if (powerMode == powerUp)
        map[i][pos] = "U";
    else if (powerMode == powerDown)
        map[i][pos] = "D";
}

void    power::findPowerOnMap(std::vector<std::string> map) {

    std::ifstream file(argv[1], std::ios::in);
    
    int i = 0;
    
    if (file) {
        std::cout << "Map is Open" << std::endl;
        while (getline(fileMap, powerMap)) {
            while (powerMap) {
                pos = powerMap.find("X");
                if (pos == std::string::npos)
                    setPowerOnMap(pos, i);
            }
            i++;
        }
        file.close();
    }
    else
        std::cerr << "Impossible to open Map" << std::endl;
}
