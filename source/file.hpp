#pragma once

#include "std_libs.hpp"

class File
{
private:
    string name;           // Имя файла
    ifstream stream;       // Поток для файла (файловый дескриптор)
public:
    File(char* new_name);  // Конструктор с параметрами
    ~File();               // Деструктор

    bool open();           // Открытие файла
    string read_line();    // Чтение строки из файла
    bool is_eof();         // Проверка на признак конца файла
};