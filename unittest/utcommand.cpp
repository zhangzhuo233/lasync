#include<iostream>
using namespace std;

#include"../lib/command.h"

int main(int argc, char const* argv[])
{
    CommandExecutor executor;
    for(int i=0; i<8; ++i)
    {
        cout<<"cmd-----------"<<i<<endl;
        executor.parsecmds(i);
        cout<<"cmd count-----------"<<executor.commands.size()<<endl;
        executor.execute_all();
    }
    return 0;
}
