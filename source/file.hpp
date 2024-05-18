#pragma once

#include "std_libs.hpp"
#include "exception.hpp"
#include "event.hpp"

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
    string read_word();
    bool is_eof();
};