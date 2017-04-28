#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <string>
using namespace std;

class LaDirOpenException
{
    public:
        LaDirOpenException(char* path);
        LaDirOpenException(std::string path);
        virtual ~LaDirOpenException(){};
    public:
        static LaDirOpenException* create_instatnce(std::string path)
        {
            return new LaDirOpenException(path);
        }
    public:
        std::string info;
};

class LaDirReadException
{
    public:
        LaDirReadException(char* path);
        LaDirReadException(std::string path);
        virtual ~LaDirReadException(){};
    public:
        static LaDirReadException* create_instatnce(std::string path)
        {
            return new LaDirReadException(path);
        }
    public:
        std::string info;
};
#endif
