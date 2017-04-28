#ifndef __DIR_READER_H__
#define __DIR_READER_H__

#include <string>
#include <vector>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "singletontemplate.h"
#include "exception.h"
#define MAXPATHLEN 1024

class LaDirReader:public LaSingletonTemplateBase<LaDirReader>
{
    public:
        LaDirReader();
        LaDirReader(const char* path_str);
        LaDirReader(std::string path_str);
        virtual ~LaDirReader();
    public:
        static LaDirReader* create_instatnce(std::string path)
        {
            return new LaDirReader(path);
        }
        static LaDirReader* create_instatnce(char* path)
        {
            return new LaDirReader(path);
        }
        vector<std::string>* read_dir()
            throw(LaDirOpenException, LaDirReadException);
    private:
        std::string path;
        std::vector<string>* entrys;//all files
};

#endif
