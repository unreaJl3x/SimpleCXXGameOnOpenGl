#include "FractionController.h"

bool FractionController::Create(string name) {
    Fraction fr;
    fr.name = name;
    fr.globalRep = 0;
    fr.favoriteRace = RACES::HUMAN;
    list.push_back(fr);

    return true;
}

Fraction *FractionController::Get(std::string n) {
    for (int i= 0;i < list.size();i++) {
        if (list[i].name==n) {
            return &list[i];
        }
    }
    return nullptr;
}