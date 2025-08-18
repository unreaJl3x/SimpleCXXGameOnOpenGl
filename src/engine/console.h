#ifndef CONSOLE_H
#define CONSOLE_H

//#define CMDS vector<string> {"help",""};
class console {
public:
    static void CommandLine(){
        string command;
        while(true) {
            cin>>command;

            if(command == "help") {
                cout<<""<<endl;
            }
        }
    }
};

#endif