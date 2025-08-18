#ifndef ENTITY_PERSON_H
#define ENTITY_PERSON_H

#include "entity.h"
#include "Equipment.h"

class entity_person : public entity {
public:
    entity_person();
    entity_person(std::string name, int_s race);

protected:
public:
    ///RACES
    int_s race ;
    //CLASS
    int_s category;
    double evasion;
    double speed;
    ///PERSON_STATES
    int_s state;
    ///PERSON_DIRECTIONS
    int_s direction;
    Equipment inv;
    vector<string> statuses; //прозвища (fallout)
    Levle levle;
    Resists resists;
    Attributes original_attributes;
    Attributes addactive_attributes;
    Fraction* fraction;
    Reputation reputations;
    int_s defense; // там с шмота + природная от расы ебать я напридумывал хуйни

public:
    bool UpdateStatsFromRace();
    void SetName(string na){this->entity::SetName(na);}
    string GetName() {return entity::GetName();}
    bool GiveCategory(string);
    void LevleUp();
    void UpdateFraction(Fraction* fr) {this->fraction=fr;};
};

#endif