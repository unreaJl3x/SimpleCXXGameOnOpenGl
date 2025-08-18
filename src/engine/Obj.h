#ifndef OBJ_H
#define OBJ_H

#include "gamedef.h"
#include "entity.h"

class Property {
public:
    string name;
    MAK<string, int> bonuses;

    Property()=default;
    Property(string name);

    bool AddBonus(string, int);
};

class Obj {
protected:
    string name;
    Sprite sprite;
    /// OBJ_TYPES
    int_s type;
    MAK<string, Property> properties;

public:
    Obj()=default;
    Obj(string name, int_s type);

    entity* ConvertToEntity();
};

#endif