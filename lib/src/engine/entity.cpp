#include "entity.h"

entity::entity(std::string name, bool hasCol, int_s health) {
    this->name = name;
    this->collision = hasCol;
    this->health = health;
}