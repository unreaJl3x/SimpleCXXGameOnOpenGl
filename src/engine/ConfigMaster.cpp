#include "ConfigMaster.h"

ConfigMaster::ConfigMaster(gamedef_t* gDate, string fileName) {
    ofstream file;
    file.open(gDate->dir.erase(gDate->dir.find_last_of('\\'),gDate->dir.back())+string(gDate->company)+"\\"+string(gDate->gameName)+"\\"+fileName,ios_base::in);
    file.put('q');
    file.close();
}