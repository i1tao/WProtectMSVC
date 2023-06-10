#include "vm_protect.hpp"

void vm_protect::protect_code(const char* filename, std::map<long, long>& user_protect_address)
{
    BuildCodeInfo build_info;
    build_info.set_filename(filename);
    VirtualMachineManage vm;
    CodeBufferInfo info;
    CPEFile file;
}
