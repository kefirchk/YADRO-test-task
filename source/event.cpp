#include "event.hpp"

void Event::set_body(string new_body)
{
    this->body = new_body;
}
    
string Event::get_body()
{
    return this->body;
}