#include "exception.h"
#include<iostream>
#include<stdio.h>
using namespace std;

LaDirOpenException::LaDirOpenException(char* path)
{
    std::string src_path(path);
    info = src_path + " Open fail.";
}

LaDirOpenException::LaDirOpenException(std::string path)
{
    info = path + " Open fail.";
}

LaDirReadException::LaDirReadException(char* path)
{
    std::string src_path(path);
    info = src_path + " Read fail.";
}

LaDirReadException::LaDirReadException(std::string path)
{
    info = path + " Read fail.";
}

LaKeyNotFoundException::LaKeyNotFoundException(std::string key)
{
    info = key + "not found";
}

LaDuplicateKeyException::LaDuplicateKeyException(std::string key)
{
     info = key + "already exists";
}

LaFileNotFoundException::LaFileNotFoundException(std::string path)
{
    info = path + "not found";
}
