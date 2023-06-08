#pragma once

#include <iostream>
#include <cstdio>
#include <cstdarg>

typedef class log_functions
{
    char* prefix_;
public:
    log_functions(void) : prefix_(nullptr)
    {

    }

    ~log_functions(void) {}

    static void warn(const char* fmt, ...)
    {
        std::va_list arg_list;

        va_start(arg_list, fmt);
        vfprintf(stdout, fmt, arg_list);
        va_end(arg_list);
    }

    static void info(const char* fmt, ...)
    {
        std::va_list arg_list;
        va_start(arg_list, fmt);
        vfprintf(stdout, fmt, arg_list);
        va_end(arg_list);
    }

    static void error(const char* fmt, ...)
    {
        std::va_list arg_list;
        va_start(arg_list, fmt);
        vfprintf(stdout, fmt, arg_list);
        va_end(arg_list);
        exit(0);
    }

    static void panic(const char* fmt, ...)
    {
        std::va_list arg_list;
        va_start(arg_list, fmt);
        vfprintf(stdout, fmt, arg_list);
        va_end(arg_list);            //exit(0);
        exit(0);
    }

    static void pass(const char* fmt, ...)
    {
        std::va_list arg_list;
        va_start(arg_list, fmt);
        vfprintf(stdout, fmt, arg_list);
        va_end(arg_list);
    }

    static void debug(const char* fmt, ...)
    {
        std::va_list arg_list;
        va_start(arg_list, fmt);
        vfprintf(stdout, fmt, arg_list);
        va_end(arg_list);
    }


}log_func_t;

