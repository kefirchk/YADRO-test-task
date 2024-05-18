#include "table.hpp"

Table::Table(size_t table_id)
{
    this->table_id = table_id;
    this->client_name = "";
    this->busy = false;
}

bool Table::is_busy() { return busy; }
string Table::get_client_name() { return this->client_name; }
size_t Table::get_table_id() { return this->table_id; }
string Table::get_client_start_time() { return get_client_start_time; }

void Table::set_busy(bool status) { this->busy = status; }
void Table::set_client_name(string name) { this->client_name = name; }
void Table::set_get_client_start_time(string get_client_start_time) { this->get_client_start_time = get_client_start_time; }

void update_revenue(string end_time, size_t price)
{

}