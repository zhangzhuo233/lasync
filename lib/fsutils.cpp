#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "fsutils.h"

bool LaFsUtils::exists(const char* path)
{
    return !access(path, F_OK);
}

bool LaFsUtils::isfile(const char* path)
{
    struct stat statbuf;
    if(stat(path, &statbuf) == -1)
        return false;
    return S_ISREG(statbuf.st_mode);
}

bool LaFsUtils::isdirectory(const char* path)
{
    struct stat statbuf;
    if(stat(path, &statbuf) == -1)
        return false;
    return S_ISDIR(statbuf.st_mode);
}

bool LaFsUtils::isdirectory_exists(const char* path)
{
    if(!LaFsUtils::exists(path) || !LaFsUtils::isdirectory(path))
        return false;
    return true;
}

bool LaFsUtils::create_temp_dir(const char* prefix, std::string& tempdir)
{
    char* tmpl = mktemp(const_cast<char*>(prefix));
    if(!tmpl)
        return false;
    if(mkdir(tmpl, 0755))
        return false;
    return true;
}

bool LaFsUtils::realpath(const char* path, std::string& rlt)
{
    char* ret = ::realpath(path, NULL);//use system function
    if(ret)
    {
        rlt.assign(ret);
        delete ret;
        return true;
    }
    return false;
}
