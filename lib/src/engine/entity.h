#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include "gamedef.h"

class entity {
protected:
    bool collision;
    string name;
    Transform transform=Transform(0,0);
    int_s health;

public:
    void SetCollision(bool collision){this-> collision = collision;};
    bool GetCollision(){return this-> collision;};

    void SetName(string n) {this-> name = n;}
    string GetName() {return this-> name;}

    void SetHealth(int_s h) {this-> health = h;}
    int_s GetHealth(){return this-> health;};

    void SetTransform(int x,int y){this->transform=Transform(x,y);}
    void AddactiveTransform(int x,int y){this->transform.Addactive(x,y);}
    Transform GetTransform(){return this-> transform;}

    entity()=default;
    entity(string name, bool hasCol = true, int_s health=10);
};


#endif