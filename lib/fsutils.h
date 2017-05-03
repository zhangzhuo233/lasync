#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
using namespace std;
#define MAXPATHLEN 1024

class LaFsUtils
{
    public:
        static bool exists(const char* path);
        static bool isfile(const char* path);
        static bool isdirectory(const char* path);
        static bool isdirectory_exists(const char* path);
        static bool create_temp_dir(const char* prefix, std::string& tempdir);
        static bool realpath(const char* path, std::string& rlt);//path to absolute pathname and save in rlt
};

#endif
