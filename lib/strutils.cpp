#include"strutils.h"

vector<string> LaStrUtils::split(const string& srcstr, const string& delimeter)
{
    vector<string> ret(0);//use ret save the spilted reault
    if(srcstr.empty())    //judge the arguments
    {
        return ret;
    }
    string::size_type pos_begin = srcstr.find_first_not_of(delimeter);//find first element of srcstr

    string::size_type dlm_pos;//the delimeter postion
    string temp;              //use third-party temp to save splited element
    while(pos_begin != string::npos)//if not a next of end, continue spliting
    {
        dlm_pos = srcstr.find(delimeter, pos_begin);//find the delimeter symbol
        if(dlm_pos != string::npos)
        {
            temp = srcstr.substr(pos_begin, dlm_pos - pos_begin);
            pos_begin = dlm_pos + delimeter.length();
        }
        else
        {
            temp = srcstr.substr(pos_begin);
            pos_begin = dlm_pos;
        }
        if(!temp.empty())
            ret.push_back(temp);
    }
    return ret;
}

bool LaStrUtils::startswith(const std::string& str, const std::string& start)
{
    int srclen = str.size();
    int startlen = start.size();
    if(srclen >= startlen)
    {
        string temp = str.substr(0, startlen);
        if(temp == start)
            return true;
    }

    return false;
}

bool LaStrUtils::endswith(const std::string& str, const std::string& end)
{
    int srclen = str.size();
    int endlen = end.size();
    if(srclen >= endlen)
    {
        string temp = str.substr(srclen - endlen, endlen);
        if(temp == end)
            return true;
    }

    return false;
}

string LaStrUtils::trim(const std::string& str)
{
    string ret;
    //find the first position of not start with space or '\t'
    string::size_type pos_begin = str.find_first_not_of(" \t");
    if(pos_begin == string::npos)
        return str;

    //find the last position of end with space or '\t'
    string::size_type pos_end = str.find_last_not_of(" \t");
    if(pos_end == string::npos)
        return str;

    ret = str.substr(pos_begin, pos_end-pos_begin);

    return ret;
}

bool LaStrUtils::inlist(const std::string& str, const std::string& key)
{
    if(str.find(key) != string::npos)
        return true;
    return false;
}

bool LaStrUtils::inlist(vector<string>& vt, const std::string& key)
{
    for(vector<string>::iterator it = vt.begin(); it != vt.end(); ++it)
    {
        if(*it == key)
            return true;
    }
    return false;
}
