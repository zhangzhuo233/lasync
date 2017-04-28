#ifndef __NFS_UTILS_HEADERS__
#define __NFS_UTILS_HEADERS__

#include <stdio.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <vector>
#include <algorithm>
#include <unistd.h>

class NfsUtils
{
    public:
        //server side
        static int startnfs();
        static int stopnfs();
        static int statusnfs();
        static int confignfs(std::string sharedir,
                std::string perssion = "*");//config /etc/exports
        //client side
        static int mountnfs(const std::string host,
                std::string sharedir,
                std::string mountpoint);
        static int is_mounted(std::string host,
                std::string sharedir,
                std::string mountpoint);
        static int umountnfs(std::string mountpoint);
        static int get_exit_code(int statuscode);

        //获取某一文件的大小
        static size_t GetFileSize(FILE *NamePath);
        //KMP算法
        static void NEXT(const std::string&T, std::vector<int>&next);
        static std::string::size_type KMP(const std::string& S,
                const std::string&T);
};

#endif
