#include "entity_person.h"

#define DEFENS_COOF 0.5f
#define INTIL_MAGIC_COOF 0.5f
#define MAGIC_STONG_COOF 2.5f
#define HEALTH_STR_COOF 0.9f
#define EVASION_AGL_COOF 0.6f
#define EVASION_STR_COOF 0.2f
#define SPEED_AGL 0.5f
#define ATRIBSUB(stats) ((this->original_attributes.stats + this->addactive_attributes.stats))
bool entity_person::UpdateStatsFromRace() {
    if (this-> original_attributes == GDEF_FAIL_ATTRIBUTE) {return false;}

    this->defense = (ATRIBSUB(strong)) * DEFENS_COOF;
    this->resists.punches = this->defense;
    this->resists.magic = ((ATRIBSUB(intilligense)) * INTIL_MAGIC_COOF)+(this->defense/MAGIC_STONG_COOF);
    this->health = ATRIBSUB(strong) * HEALTH_STR_COOF;
    this->evasion = ((ATRIBSUB(agility)) * EVASION_AGL_COOF) + ((ATRIBSUB(strong)) * EVASION_STR_COOF);
    this->speed = (ATRIBSUB(agility)) * SPEED_AGL;
    return true;
}

entity_person::entity_person() {
    this->direction = PERSON_DIRECTIONS::FRONT;
    this->state = PERSON_STATES::STABLE;
    this->levle = 1;
    this->race = RACES::HUMAN;
    this->original_attributes = GetAttributesOnRace(this->race);
    if(!UpdateStatsFromRace()){cout<<"Race fail.";}
    this->name = "Alive Meat";
    this->collision = true;
    this->levle = Levle();
    this->fraction=nullptr;
    this->inv = Equipment(20);
};

entity_person::entity_person(std::string name, int_s race) {
    entity_person();
    this-> name = name;
    this-> race = race;
    this->original_attributes = GetAttributesOnRace(this->race);
    if(!UpdateStatsFromRace()){cout<<"Race fail.";}
}

void entity_person::LevleUp() {
    if(this->levle.Up()) {
        this->addactive_attributes = GetAttributesOnRace(this->race,1);
    }
}
