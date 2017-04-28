#include<iostream>
using namespace std;

#include"../lib/strutils.h"

int main(int argc, char const* argv[])
{
    vector<string> ret = LaStrUtils::split("aa bb cc ed ff", " ");
    cout<<"====split test result===="<<endl;
    for(vector<string>::iterator it = ret.begin(); it < ret.end(); ++it)
        cout << *it<<endl;
    cout<<"====startswith/endswith test result===="<<endl;
    if(LaStrUtils::startswith("startsof", "start")
            && LaStrUtils::endswith("endsof\t  \t  ", " "))
        cout<<"true"<<endl;
    cout<<"====trim test result===="<<endl;
    //cout<<LaStrUtils::trim("   \t  aa bb \t  aa \t    ");
    cout<<LaStrUtils::trim("   \t  aa \t bb \t  aa   \t  ")<<"OK"<<endl;
    cout<<"====in_list test result===="<<endl;
    if(LaStrUtils::inlist("ab cd ef", "cf"))
        cout<<"inlist"<<endl;
    else
        cout<<"none of list"<<endl;
    vector<string> vt;
    vt.push_back("aa");
    vt.push_back("bb");
    vt.push_back("cc");
    vt.push_back("dd");
    if(LaStrUtils::inlist(vt, "df"))
        cout<<"inlist"<<endl;
    else
        cout<<"none of list"<<endl;
    return 0;
}
