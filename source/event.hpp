#pragma once
#include "std_libs.hpp"

class Event
{
private:
    string time;         // Время события
    size_t event_id;     // ID события
    string client_name;  // Имя клиента, с которым произошло событие
    size_t table_number; // Номер стола, за который (возможно) садится клиент
public:

    // Геттеры
    string get_time();
    string get_client_name();
    size_t get_event_id();
    size_t get_table_number();

    // Сеттеры
    void set_time(const string& time);
    void set_client_name(const string& client_name);
    void set_event_id(const size_t& event_id);
    void set_table_number(const size_t& table_number);
};