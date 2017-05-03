#include <iostream>
using namespace std;
#include "../lib/fsutils.h"

int main(int argc, char const* argv[])
{
    std::string rpath;
    cout << LaFsUtils::isfile("/etc") << endl;              //0
    cout << LaFsUtils::isfile("/etc/exports") <<endl;       //1
    cout << LaFsUtils::isdirectory("/etc") << endl;         //1
    cout << LaFsUtils::isdirectory("/etc/exports") <<endl;  //0
    cout << LaFsUtils::isdirectory_exists("/etc/exports") <<endl;//0
    cout << LaFsUtils::isdirectory_exists("/etc") <<endl;   //1
    cout << LaFsUtils::exits("/etc") << endl;               //1
    cout << LaFsUtils::exits("/etc/exports") <<endl;        //1
    cout << LaFsUtils::exits("none exist file") <<endl;     //0
    LaFsUtils::realpath("../lib", rpath);
    cout << rpath << endl;
    char path[20] = "Test-XXXXXX";
    //LaFsUtils::create_temp_dir("Tesr-XXXXXX", rpath);//core dump, because argu1 is const
    LaFsUtils::create_temp_dir(path,rpath);
    return 0;
}
