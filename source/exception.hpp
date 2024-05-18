#pragma once
#include "std_libs.hpp"

class Exception
{
private:
    size_t id;
    string description;
public:
    Exception(size_t id, string description);
    string get_description();
    size_t get_id();
};

