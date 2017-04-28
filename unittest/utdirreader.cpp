#include <iostream>
using namespace std;
#include "../lib/dirreader.h"

int main(int argc, char const* argv[])
{
    //LaDirReader* pdir = LaDirReader::create_instatnce("/111");
    LaDirReader* pdir = new LaDirReader("/111");
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
    catch(...)
    {
        cerr<<"Error."<<endl;
    }
    return 0;
}
