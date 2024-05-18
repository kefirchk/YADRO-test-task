#include "file.hpp"

// Конктруктор с параметрами
File::File(char* name)
{
    this->name = name;
}

// Деструктор
File::~File()
{
    stream.close();
}

// Открытие файла
bool File::open()
{
    stream.open(this->name);
    if (!stream.is_open()) // если файл не открыт
    {
        cerr << "[ERROR]: File is not open" << endl; // сообщить об этом
        return false;
    }
    return true;
}

// Чтения строки из файла
string File::read_line()
{
    string line;
    if (!getline(stream, line)) {
        cerr << "[ERROR]: Failed to read line" << endl;
        return "";
    }
    return line;
}

// Проверка признака конца файла
bool File::is_eof()
{
    return stream.eof();
}