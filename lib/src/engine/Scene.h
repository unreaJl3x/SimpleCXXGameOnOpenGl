#ifndef SCENE_H
#define SCENE_H

#include <fstream>
#include <vector>
#include "entity_person.h"
#include "FractionController.h"
#include "ImageController.h"

class Scene {
public:
    WH screen;
    vector<entity> enList;
    vector<entity_person> epList;

    FractionController fControll;
    ImageController iControll;
    //QuestController qControll

    void AddEntity(entity);
    void AddEntity(entity_person);

    bool LoadFrom(std::string path);
    bool SaveTo(std::string path);

    bool Prepare();

    /// NEED DEBUGMODE!!!
    void PrintWorldToConsole();
    /// NEED DEBUGMODE!!!
    void PrintEntity();
    /// NEED DEBUGMODE!!!
    void PrintEntityPerson();
};


#endif