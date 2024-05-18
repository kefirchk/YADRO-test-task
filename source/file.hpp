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

    string read_line();
    string read_word();
    unsigned int read_number();
};