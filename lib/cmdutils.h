#ifndef __CMD_UTILS_H__
#define __CMD_UTILS_H__

#include <string>
#include <unistd.h>
using namespace std;
class LaCmdUtils
{
    public:
        static int parse_args(int argc, char** argv, const char* args, int& cmd, std::string& dest);
        static void usage();
};

#endif
