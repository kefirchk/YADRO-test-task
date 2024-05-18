#include "exception.hpp"

Exception::Exception(string description)
{
    this->description = description;
}

string Exception::get_description()
{
    return this->description;
}