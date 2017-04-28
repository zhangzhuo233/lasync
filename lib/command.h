#ifndef __COMMAND__
#define __COMMAND__

#include <deque>
using namespace std;

//command block
class Command
{
public:
    Command(){}
    virtual ~Command(){}
    virtual int execute(){}
};
//-f
class FileSyncCommand : public Command
{
public:
    FileSyncCommand();
    virtual ~FileSyncCommand();
    virtual int execute();
};
//-p
class PkgCommand : public Command
{
public:
    PkgCommand();
    virtual ~PkgCommand();
    virtual int execute();
};
//-u
class UpgradeCommand : public Command
{
public:
    UpgradeCommand();
    virtual ~UpgradeCommand();
    virtual int execute();;
};
//execute command
class CommandExecutor
{
public:
    CommandExecutor();
    ~CommandExecutor();
    int enquecmd(Command* cmd);
    int dequecmd();
    int execute_all();
    int parsecmds(int cmd);
public:
    deque<Command*> commands;
};

#endif
