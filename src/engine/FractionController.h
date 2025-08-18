
#ifndef FRACTIONMANAGER_H
#define FRACTIONMANAGER_H

#include <iostream>
#include <vector>
#include "gamedef.h"

class FractionController {
    vector<Fraction> list;
public:
    bool Create(string name);
    bool Set();
    Fraction* Get(string n);
    bool Remove();
};

#endif