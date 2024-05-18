#pragma once
#include "std_libs.hpp"

class Exception
{
private:
    size_t id;           // ID ошибки
    string description;  // Описание ошибки
public:
    // Контруктор с параметрами
    Exception(size_t id, string description);  
    
    // Геттеры
    string get_description();
    size_t get_id();
};

