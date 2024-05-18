#include "event.hpp"

string Event::get_time() { return time; }
string Event::get_client_name() { return client_name; }
size_t Event::get_event_id() { return event_id; }
size_t Event::get_table_number() { return table_number; }

void Event::set_time(const string& time) { this->time = time; }
void Event::set_client_name(const string& client_name) { this->client_name = client_name; }
void Event::set_event_id(const size_t& event_id) { this->event_id = event_id; }
void Event::set_table_number(const size_t& table_number) { this->table_number = table_number; }