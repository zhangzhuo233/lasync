#include <iostream>/*for cout*/
#include <stdlib.h>/*for exit*/

#include <unistd.h>/*for getuid*/
#include <sys/types.h>/*for getuid*/

using namespace std;

struct Message
{
    int cmd;
    char tag[0];
};

int main(int argc, char const* argv[])
{
    if(getuid())
    {
        cerr << "Permission denied, only root can run this tool." << endl;
        exit(1);
    }

    return 0;
}
