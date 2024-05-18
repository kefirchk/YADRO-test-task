#include "file.hpp"

File::File(char* name)
{
    this->name = name;
}

File::~File()
{
    stream.close();
}

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

string File::read_line()
{
    string line;
    if (!getline(stream, line)) {
        cerr << "[ERROR]: Failed to read line" << endl;
        return "";
    }
    return line;
}

bool File::is_eof()
{
    return stream.eof();
}