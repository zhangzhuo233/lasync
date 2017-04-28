#include <iostream>
#include "command.h"

using namespace std;

FileSyncCommand::FileSyncCommand()
{
    cout<<"in fscmd ctor"<<endl;
}

FileSyncCommand::~FileSyncCommand()
{
    cout<<"in fscmd dtor"<<endl;
}

int FileSyncCommand::execute()
{
    cout<<"in fscmd exeute"<<endl;
    return 0;
}

PkgCommand::PkgCommand()
{
    cout<<"in pkgcmd ctor"<<endl;
}

PkgCommand::~PkgCommand()
{
    cout<<"in pkgcmd dtor"<<endl;
}

int PkgCommand::execute()
{
    cout<<"in pkcmd execute"<<endl;
    return 0;
}

UpgradeCommand::UpgradeCommand()
{
    cout<<"in upgradecmd ctor"<<endl;
}

UpgradeCommand::~UpgradeCommand()
{
    cout<<"in upgradecmd dtor"<<endl;
}

int UpgradeCommand::execute()
{
    cout<<"in upgradecmd execute"<<endl;
    return 0;
}

CommandExecutor::CommandExecutor()
{
    cout<<"in cmdexe ctor"<<endl;
}

CommandExecutor::~CommandExecutor()
{
    if(!commands.empty())
    {
         for(deque<Command*>::iterator it = commands.begin();
                 it != commands.end(); ++it)
         {
             delete (*it);
             *it = NULL;
         }
    }
    cout<<"in cmdexe dtor"<<endl;
}

int CommandExecutor::enquecmd(Command* cmd)
{
    commands.push_back(cmd);
    return 0;
}

int CommandExecutor::dequecmd()
{
    if(!commands.empty())
    {
        commands.pop_front();
    }
    return 0;
}

int CommandExecutor::execute_all()
{
    cout<<"execute all commands in executor"<<endl;
    while(!commands.empty())
    {
        deque<Command*>::iterator comhead = commands.begin();
        (*comhead)->execute();

        delete *comhead;
        *comhead = NULL;

        commands.pop_front();
    }
    return 0;
}

int CommandExecutor::parsecmds(int cmd)
{
    int tmp = cmd;
    if(cmd < 1)
        return -1;
    if(cmd > 7)
        return -1;
    if(tmp & 1)
    {
        FileSyncCommand* pfs = new FileSyncCommand();
        enquecmd(pfs);
    }
    tmp>>=1;
    if(tmp & 1)
    {
         PkgCommand* ppk = new PkgCommand();
         enquecmd(ppk);
    }
    tmp>>=1;
    if(tmp & 1)
    {
         UpgradeCommand* pup = new UpgradeCommand();
         enquecmd(pup);
    }
    return 0;
}

