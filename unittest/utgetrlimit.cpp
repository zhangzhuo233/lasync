#include<iostream>
#include<stdlib.h>
using namespace std;


#include <sys/resource.h>

int main(int argc, char const* argv[])
{
    int i=0;
    rlimit ret;
    getrlimit(RLIMIT_NOFILE, &ret);
    cout<<(ret.rlim_cur)<<endl;
    return 0;
}
