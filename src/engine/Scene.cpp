#include "Scene.h"
#include <string>
#ifdef DEBUGMODE

void Scene::AddEntity(entity_person ep) {epList.push_back(ep);}

void Scene::PrintWorldToConsole() {cout<<"1"<<endl;}

void Scene::PrintEntityPerson() {
    cout <<"|       Entity(person) List        |"<<endl;
    int* count = new int();*count=0;
    for(auto ep : this->epList) {
        cout <<"("<<*count<<") | "<< ep.GetName() << endl;
        *count++;
    }
    //free(count);
    cout<<endl<<"Select( '-1' - all ): "<<endl<<endl; int choice;
    cin >>choice;
    cout<<endl;
    int choice_int = choice;
    //free(choice);
    entity_person* selected=&epList[choice_int];

    cout << "_________[_[   " << (selected->GetName()) << "   ]_]________"<<endl;
    cout << "| [LVL]    |_" << selected->levle.GetLevle() << "_| , [RACE] " << GetRaceNameOnInt(selected->race)<<"   |" << endl;
    cout <<"|         ("<<selected->levle.GetCPoints()<<"/"<<selected->levle.GetNPoints()<<")"<<endl<<endl;
    cout << "| [FRACTION]: '" << ( selected->fraction == nullptr ? "None" : selected->fraction->name)<<"'  repiutation(" << (selected->fraction==nullptr ? "" : to_string(selected->fraction->globalRep)) <<")"<< endl;
    cout<<"|" << endl<<"| [ATTRIBUTES]"<<endl<<"|       strong: "<<selected->original_attributes.strong<<"+("<<selected->addactive_attributes.strong<<")        agility: "<<selected->original_attributes.agility<<"+("<<selected->addactive_attributes.agility<<")        intiligence: "<<selected->original_attributes.intilligense<<"+("<<selected->addactive_attributes.intilligense<<")"<<endl<<"|";
    cout << endl << "| [STATS]" << endl << "|       speed: " << selected->speed <<endl<< "|       evasion: " << selected->evasion<<endl << "|       defense: " << selected->defense <<endl << "|       health: "<< selected->GetHealth() << endl;
    cout <<"|"<< endl<<"| [RESISTS]"<<endl<<  "|       magic: "<<selected->resists.magic<<endl<<"|       punches: "<<selected->resists.punches<<endl;
    cout<<"| [REPUTATIONS]"<<endl;
    selected->inv=Equipment(20);
    cout<<"|"<<endl<<"|       [EQUIPMENT]"<<endl;//cout<<selected->inv.size()<<endl;
    cout<<"|     ";
    for(int i = 1; i <= selected->inv.size();i++) {
        cout << "|-|";
        if ( (i % 5) == 0) {
            cout<<endl<<"|     ";
        }
    }
    cout<<endl;
    cout <<"|______________________________|"<<endl;
    getchar();
}
#endif