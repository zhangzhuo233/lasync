#include <iostream>
#include <stdlib.h>
#include "../lib/nfsutils.h"
using namespace std;

int main(int argc, char const* argv[])
{
    NfsUtils::startnfs();
    NfsUtils::statusnfs();
    NfsUtils::confignfs("/data", "*");
    NfsUtils::umountnfs("/mnt");
    NfsUtils::mountnfs("ucn02", "/data", "/mnt/");
    NfsUtils::is_mounted("ucn02", "/data", "/mnt/");
    return 0;
}
