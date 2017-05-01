#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
#include "../lib/dirreader.h"

int main(int argc, char const* argv[])
{
    //LaDirReader* pdir = LaDirReader::create_instatnce("/111");
    LaDirReader* pdir = new LaDirReader("/etc");
    vector<std::string>* entries;
    try
    {
        entries = pdir->read_dir();
    }
    catch(LaDirOpenException &e)
    {
     //   cout<<"ddddd"<<endl;
        cerr<<e.info<<endl;
    }
    catch(LaDirReadException &e)
    {
     //   cout<<"edddd"<<endl;
        cerr<<e.info<<endl;
    }
    sort(entries->begin(), entries->end());
    for(vector<string>::iterator it = entries->begin(); it != entries->end(); ++it)
    {
         cout<<*it<<'\t';
    }
    return 0;
}
