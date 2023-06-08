#pragma once
#include <map>
#include <vector>

#include "log_functions.h"
class vm_protect : public log_functions
{
public:
    vm_protect(bool load_file_ok, const CPEFile& dis_file)
        : load_file_ok_(load_file_ok),
          dis_file_(dis_file)
    {
    }

    void get_table_addr(CPESection& section, std::vector<long>& addr_table_entry, std::vector<long*>& addr_table_entry_point);
    void protect_code(const char* filename, std::map<long, long>& user_protect_address);
private:
    //BuildCodeInfo build_info;
    bool load_file_ok_;
    CPEFile dis_file_;
};