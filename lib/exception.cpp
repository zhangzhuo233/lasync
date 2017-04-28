#include "exception.h"
#include<iostream>
#include<stdio.h>
using namespace std;

LaDirOpenException::LaDirOpenException(char* path)
{
   // cout<<"aaaaaaaaaaaaaaaaaaaa"<<endl;
    std::string src_path(path);
    //cout<<path<<endl;
    //printf("path = %s\n",path);
    //cout<<"aaaaddddddaaaaaaaaaaaaaaaa"<<endl;
    info = src_path + " Open fail.";
}
LaDirOpenException::LaDirOpenException(std::string path)
{
    //cout<<"baaaaaaaaaaaaaaaaaaa"<<endl;
    info = path + " Open fail.";
}
LaDirReadException::LaDirReadException(char* path)
{
    //cout<<"caaaaaaaaaaaaaaaaaaa"<<endl;
    std::string src_path(path);
    info = src_path + " Read fail.";
}
LaDirReadException::LaDirReadException(std::string path)
{
    //cout<<"daaaaaaaaaaaaaaaaaaa"<<endl;
    info = path + " Read fail.";
}
