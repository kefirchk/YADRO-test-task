#pragma once

#include "std_libs.hpp"

class Table
{
private:
    size_t table_id;
    string client_name;
    bool busy;
    string client_start_time;
    size_t revenue; // выручка
public:
    Table(size_t table_id);

    bool is_busy();
    string get_client_name();
    size_t get_table_id();
    string get_client_start_time();

    void set_busy(bool status);
    void set_client_name(string name);
    void set_client_start_time(string client_start_time);

    void update_revenue(string end_time, size_t price);
};