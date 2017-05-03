#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <string>
using namespace std;

class LaException
{
    public:
        virtual ~LaException(){}
    public:
        std::string info;
};
class LaDirOpenException : public LaException
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
};

class LaDirReadException: public LaException
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
};

class LaFileNotFoundException: public LaException
{
    public:
        LaFileNotFoundException(std::string path);
        virtual ~LaFileNotFoundException(){}
};

class LaDirCanNotReadException: public LaException
{
    public:
        LaDirCanNotReadException(std::string path);
        virtual ~LaDirCanNotReadException(){}
};

class LaHardwareException: public LaException
{
    public:
        LaHardwareException(std::string hwtype);
};

class LaWorkloadException: public LaException
{
    public:
        LaWorkloadException();
        virtual ~LaWorkloadException(){}
};

class LaFileCanNotAccessException: public LaException
{
    public:
        LaFileCanNotAccessException();
        virtual ~LaFileCanNotAccessException(){}
};

class LaKeyNotFoundException: public LaException
{
    public:
        LaKeyNotFoundException(std::string key);
        virtual ~LaKeyNotFoundException(){}
};

class LaDuplicateKeyException: public LaException
{
    public:
        LaDuplicateKeyException(std::string key);
        virtual ~LaDuplicateKeyException(){}
};

#endif
