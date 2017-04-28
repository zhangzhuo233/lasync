#include <errno.h>
#include "dirreader.h"//opendir readdir
#include <iostream>
using namespace std;


LaDirReader::LaDirReader()
{
    path = "/tmp";
    entrys = new vector<std::string>();
}
LaDirReader::LaDirReader(const char* path_str)
{
    //cout<<"Ldr ctr"<<endl;
    path = path_str;
    entrys = new vector<std::string>();
}
LaDirReader::LaDirReader(std::string path_str):path(path_str)
{
    entrys = new vector<std::string>();
}
LaDirReader::~LaDirReader()
{
    delete entrys;
    entrys = NULL;
}
vector<std::string>* LaDirReader::read_dir()
                throw(LaDirOpenException, LaDirReadException)
{
    //cout<<"111111111111111111111111111111111111"<<endl;
    char buffer[MAXPATHLEN];
    char *rpath = NULL;
    rpath = realpath(path.c_str(), buffer);//if path is not exits, rpath will be NULL, this is a important problem
    //cout<<"211111111111111111111111111111111111"<<endl;
    if(access(rpath, F_OK | R_OK))
    {
    //cout<<"311111111111111111111111111111111111"<<endl;
        throw LaDirOpenException(path.c_str());
    //cout<<"411111111111111111111111111111111111"<<endl;
    }

    DIR* dir;
    struct dirent* entry;
    if(!(dir = opendir(path.c_str())))
    {
         throw LaDirOpenException(path.c_str());
    }

    while((entry = readdir(dir)))
    {
        (*entrys).push_back(entry->d_name);
    }
    closedir(dir);
    return entrys;
}
