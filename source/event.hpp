#pragma once
#include "std_libs.hpp"

class Event
{
private:
    string time;
    int id;
    string body;
public:
    void set_body(string new_body);
    string get_body();
};