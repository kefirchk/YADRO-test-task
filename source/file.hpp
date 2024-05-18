#pragma once

#include "std_libs.hpp"

class File
{
private:
    string name;
    ifstream stream;
public:
    File(char* new_name);
    ~File();

    bool open();
    string read_line();
    bool is_eof();
};