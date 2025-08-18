#ifndef IMAGECONTROLLER_H
#define IMAGECONTROLLER_H

#include "gamedef.h"
#include <fstream>
#define SPRT_FOLDER "C:\\Users\\unreaJl3x\\CLionProjects\\SimpleCXXRPGOnDX9\\sprt\\"
class ImageController {
MAK<string,string> pathes;
public:
    bool Add(string name, string path) {
        if (path[0]!='C' && path[1]!=':') {
            path = SPRT_FOLDER + path;
        }
        fstream file; file.open(path);
        if (!file.is_open()) {cout<<"File("<<name<<") on "<<path<<" not load."<<endl;return false;}
        return pathes.Add(name,path);
    }
    bool Remove(string name) {
        return pathes.Remove(name);
    }
    string Get(string name){ return (pathes[name]); }
};

#endif