#include <iostream>
#include "cmdutils.h"


int LaCmdUtils::parse_args(int argc, char** argv, const char* args, int& cmd, std::string& dest)
{
    int opt = 0;
    while((opt = getopt(argc, argv, args)) != -1)
    {
        switch(opt)
        {
            //file sync
            case 'f':
                cmd |= 1;
                break;
            //package install
            case 'p':
                cmd |= 1<< 1;
                break;
            //upgrade
            case 'u':
                cmd |= 1<< 2;
                break;
            //node list
            case 'm':
                dest = optarg;
                break;
            //argument error, show error message
            default:
                LaCmdUtils::usage();
                return -1;
        }
    }
    return 0;
}
void LaCmdUtils::usage()
{
    const char* usage = "\t-f:synchronize file\n\t-p:synchronize package\
                         \n\t-u:upgrade package\n\t-m:node list to do above \
actions, if no -m all node will be synchronized\n";
    cerr << usage << endl;
}
