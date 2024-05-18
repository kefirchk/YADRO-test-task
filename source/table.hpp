#pragma once

#include "std_libs.hpp"

class Table
{
private:
    size_t table_id;          // Номер стола
    string client_name;       // Имя клиента, сидящего за столом
    bool busy;                // Признак занятости стола
    string client_start_time; // Время, когда клиент сел за стол
    string full_time;         // Полное время работы стола

    size_t time_to_minutes(string time);                  // Перевод времени из формата XX:XX в минуты
    string add_times(string start_time, string end_time); // Сложение двух значений времени в формате XX:XX
    string sub_times(string start_time, string end_time); // Разница двух значений времени в формате XX:XX

public:
    Table(size_t table_id);   // Конструктор с параметрами

    // Геттеры
    bool is_busy();          
    string get_client_name();
    size_t get_table_id();
    string get_client_start_time();
    string get_full_time();

    // Сеттеры
    void set_busy(bool status);
    void set_client_name(string name);
    void set_client_start_time(string client_start_time);

    void update_full_time(string client_end_time);   // Обновление времени работы стола
    size_t calc_revenue(size_t price);               // Подсчет выручки стола
};