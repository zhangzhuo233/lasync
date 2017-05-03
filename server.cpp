#include <iostream>/*for cout*/
#include <stdlib.h>/*for exit*/

#include <unistd.h>/*for getuid*/
#include <sys/types.h>/*for getuid*/

#include "lib/cmdutils.h"/*for cmdutils*/
using namespace std;

struct Message
{
    int cmd;
    char tag[0];
};

int main(int argc, char** argv)
{
    if(getuid())
    {
        cerr << "Permission denied, only root can run this tool." << endl;
        exit(1);
    }
    const char* args = "fpum:";
    int cmd = 0;
    std::string dest;

    int ret = LaCmdUtils::parse_args(argc, argv, args, cmd, dest);
    if(ret || cmd)
    {
        LaCmdUtils::usage();
        exit(1);
    }


    return 0;
}
