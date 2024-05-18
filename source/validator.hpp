#pragma once

#include "std_libs.hpp"
#include "event.hpp"

class Validator
{
public:
    bool is_number(string line, size_t& number);
    bool is_two_time(string line, string& time_1, string& time_2);
    bool is_event(string line, Event& event);
};