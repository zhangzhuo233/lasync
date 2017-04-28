#ifndef __STR_UTILS_H__
#define __STR_UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iterator>

#include <sys/types.h>
#include <regex.h>

using namespace std;

class LaStrUtils
{
    public:
        static vector<string> split(const string& srcstr, const string& delimeter = ";");//split the string by delimeter
        //mv the result by spilting to vector
        static bool startswith(const std::string& str, const std::string& start);
        static bool endswith(const std::string& str, const std::string& end);
        static string trim(const std::string& str);//delete the space or '\t' of str
        static bool inlist(vector<string>& vt, const std::string& key);//judge key is/is not in vt
        static bool inlist(const std::string& str, const std::string& key);//judge key is/is not in str
};

#endif
