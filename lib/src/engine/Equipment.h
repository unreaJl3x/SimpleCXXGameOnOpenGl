#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <iostream>
#include <vector>

#include "gamedef.h"
#include "Obj.h"

struct Slot {
    Obj object;
    int_s type;
};

class Equipment {
public:
    std::vector<Slot> slots;
public:
    Equipment()=default;
    Equipment(int_s SlotsCount);
    int size();
};

#endif