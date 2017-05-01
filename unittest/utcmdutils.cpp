#include <iostream>
using namespace std;
#include "../lib/cmdutils.h"
int main(int argc, char** argv)
{
    int cmd = 0;
    std::string dest;
    LaCmdUtils::parse_args(argc, argv, "fpum:", cmd, dest);
    cout << cmd << endl;
    cout << dest << endl;
    return 0;
}
