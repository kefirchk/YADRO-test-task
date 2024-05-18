#pragma once
#include "std_libs.hpp"

class Exception
{
private:
    string description;
public:
    Exception(string description);
    string get_description();
};

