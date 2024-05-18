#include "exception.hpp"

Exception::Exception(size_t id, string description)
{
    this->id = id;
    this->description = description;
}

string Exception::get_description()
{
    return this->description;
}

size_t Exception::get_id()
{
    return this->id;
}
