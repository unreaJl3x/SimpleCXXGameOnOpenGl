#ifndef CONFIGMASTER_H
#define CONFIGMASTER_H

#include <iostream>
#include <fstream>
#include "gamedef.h"
using namespace std;

class ConfigMaster {
MAK<string, string> params;
public:
    ConfigMaster(gamedef_t* gameDate, string fileName = "settings.cfg");
    bool AddParam();
    string GetParam(string);
};

#endif