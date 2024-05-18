#include "table.hpp"

// Конструктор с параметрами
Table::Table(size_t table_id)
{
    this->table_id = table_id;
    this->client_name = "";
    this->busy = false;
    this->full_time = "00:00";
}

// Геттеры
bool Table::is_busy() { return this->busy; }
string Table::get_client_name() { return this->client_name; }
size_t Table::get_table_id() { return this->table_id; }
string Table::get_client_start_time() { return this->client_start_time; }
string Table::get_full_time() { return this->full_time; }

// Подсчет выручки стола
size_t Table::calc_revenue(size_t price)
{ 
    size_t time_in_minutes = this->time_to_minutes(full_time);
    size_t hours, minutes;
    
    minutes = time_in_minutes % 60;
    hours = (time_in_minutes - minutes) / 60;
    if(minutes > 0)
        ++hours;

    return hours * price;
}

// Сеттеры
void Table::set_busy(bool status) { this->busy = status; }
void Table::set_client_name(string name) { this->client_name = name; }
void Table::set_client_start_time(string client_start_time) { this->client_start_time = client_start_time; }

// Обновление полного времени работы стола
void Table::update_full_time(string client_end_time)
{
    string client_time = this->sub_times(this->client_start_time, client_end_time);
    this->full_time = this->add_times(this->full_time, client_time);
}

// Перевод времени из формата XX:XX в минуты
size_t Table::time_to_minutes(string time)
{
    size_t hours = (time[0] - '0') * 10 + time[1] - '0';
    size_t minutes = (time[3] - '0') * 10 + time[4] - '0';
    return hours * 60 + minutes;
}

// Сложение двух значений времени в формате XX:XX
string Table::add_times(string start_time, string end_time)
{
    int minutes1 = ((start_time[0] - '0') * 10 + start_time[1] - '0') * 60 + (start_time[3] - '0') * 10 + start_time[4] - '0';
    int minutes2 = ((end_time[0] - '0') * 10 + end_time[1] - '0') * 60 + (end_time[3] - '0') * 10 + end_time[4] - '0';

    int total_minutes = minutes1 + minutes2;
    int hours = total_minutes / 60;
    int minutes = total_minutes % 60;

    std::string result = "";
    result += (hours / 10) + '0';
    result += (hours % 10) + '0';
    result += ":";
    result += (minutes / 10) + '0';
    result += (minutes % 10) + '0';

    return result;
}

// Разница двух значений времени в формате XX:XX
string Table::sub_times(string start_time, string end_time)
{
    int minutes1 = this->time_to_minutes(start_time);
    int minutes2 = this->time_to_minutes(end_time);

    int time_diff = std::abs(minutes2 - minutes1);

    int hours = time_diff / 60;
    int mins = time_diff % 60;

    std::string formatted_time = "";
    formatted_time += (hours / 10) + '0';
    formatted_time += (hours % 10) + '0';
    formatted_time += ":";
    formatted_time += (mins / 10) + '0';
    formatted_time += (mins % 10) + '0';

    return formatted_time;
}