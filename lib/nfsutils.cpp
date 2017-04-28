#include <iostream>
#include <stdlib.h>
#include "nfsutils.h"
using namespace std;

#ifdef __UBUNTU__
std::string servername = " nfs-kernel-server";
#else
std::string servername = " nfs";
#endif

size_t NfsUtils::GetFileSize(FILE *NamePath)
{
    size_t size = 0;
    fseek(NamePath, 0, SEEK_END);
    size = ftell(NamePath);
    return size;
}
void NfsUtils::NEXT(const std::string&T, std::vector<int>&next)
{
    next[0]=-1;
    for(int i=1;i<T.size();i++)
    {
        int j=next[i-1];
        while(T[i-1]!=T[j] &&j >=0)
            j=next[j];//递推计算
        if(T[i-1]==T[j])
            next[i]=j+1;
        else
            next[i]=0;
    }
}
string::size_type NfsUtils::KMP(const std::string& S, const std::string&T)
{
    //利用模式串T的next函数求T在主串S中的个数count的KMP算法
    //其中T非空，
    vector<int>next(T.size());
    NfsUtils::NEXT(T,next);
    string::size_type index,count=0;
    for(index=0;index<S.size();++index){
        int pos=0;
        string::size_type iter=index;
        while(pos<T.size()&&iter<S.size()){
            if(S[iter]==T[pos]){++iter;++pos;}
            else{
                if(pos==0) ++iter;
                else pos=next[pos-1]+1;
            }
        }
        if(pos==T.size() && (iter-index)==T.size()) ++count;
    }
    return count;
}
int NfsUtils::get_exit_code(int statuscode)
{
    if(statuscode == 0)
    {
        return 0;
    }
    else if(WIFEXITED(statuscode))
    {
        return WEXITSTATUS(statuscode);
    }
}
//server side
int NfsUtils::startnfs()
{
    std::string cmd("systemctl start");
    cmd += servername + " >/dev/null 2>&1";
    int ret = system(cmd.c_str());
    return get_exit_code(ret);
}
int NfsUtils::statusnfs()
{
    std:string cmd("systemctl status");
    cmd += servername + " >/dev/null 2>&1";
    int ret = system(cmd.c_str());
    return get_exit_code(ret);
}
int NfsUtils::stopnfs()
{
    std::string cmd("systemctl stop");
    cmd += servername + " >/dev/null 2>&1";
    int ret = system(cmd.c_str());
    return get_exit_code(ret);
}
int NfsUtils::confignfs(std::string sharedir,
        std::string perssion)
{
    std::string conffile = "/etc/exports";
    FILE* fp = fopen("/etc/exports", "r");
    int fd = open(conffile.c_str(), O_RDWR |O_APPEND);

    std::string confline = sharedir + ' '+ perssion +"(rw,sync,subtree_check)";
    std::string ackconfline = '#' + sharedir + ' '+ perssion +"(rw,sync,subtree_check)";//如果被注释掉了也要追加

    string::size_type len = confline.length();
    size_t size = GetFileSize(fp);
    char *buffer = (char*)malloc(sizeof(char)*size);
    read(fd, buffer, size);

    std::string::size_type count = KMP(buffer,confline);
    std::string::size_type ackcount = KMP(buffer, ackconfline);

    if(count == 0 || count == ackcount)
        write(fd, confline.c_str(), len);
    close(fd);

    free(buffer);
    return 0;
}
//client side
int NfsUtils::mountnfs(const std::string host,
        std::string sharedir,
        std::string mountpoint)
{
    std::string cmd("mount ");
    cmd += host + ':' + sharedir + ' ' + mountpoint + " >/dev/null 2>&1";
    int ret = system(cmd.c_str());
    return get_exit_code(ret);
}
int NfsUtils::is_mounted(std::string host,
        std::string sharedir,
        std::string mountpoint)
{
    std::string cmd("mount ");
    cmd = cmd + "|grep 'ucn02:/data on /mnt'" + " >/dev/null 2>&1";
    int ret = system(cmd.c_str());
    return get_exit_code(ret);
}
int NfsUtils::umountnfs(std::string mountpoint)
{
    std::string cmd("umount ");
    cmd += mountpoint + " >/dev/null 2>&1";
    int ret = system(cmd.c_str());
    return get_exit_code(ret);
}
