#include "exception.hpp"

// Конструктор с параметрами
Exception::Exception(size_t id, string description)
{
    this->id = id;
    this->description = description;
}

// Получение описания ошибки
string Exception::get_description()
{
    return this->description;
}

// Получение ID ошибки
size_t Exception::get_id()
{
    return this->id;
}
