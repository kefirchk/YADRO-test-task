#pragma once

#include "std_libs.hpp"
#include "event.hpp"

class Validator
{
public:
    bool is_number(string line, size_t& number);                   // Валидация числа
    bool is_two_time(string line, string& time_1, string& time_2); // Валидация двух подряд идущих значений времени в формате XX:XX
    bool is_event(string line, Event& event);                      // Валидация события
};