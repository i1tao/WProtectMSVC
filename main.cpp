#include <iostream>
#include <map>

#include "vm_protect.hpp"

auto main(int argc, char* argv[]) -> int
{
    if (argc >= 3)
    {

        if (strcmp(argv[1], "-f") == 0)
        {
            vm_protect vm;
            std::map<long, long> xxx;
            vm.protect_code(argv[2], xxx);
            return 0;
        }
    }
    else
    {
        printf("Input Format:\n"
            "WProtect -f {filename}\n");
        return -1;
    }
    return 0;
}
