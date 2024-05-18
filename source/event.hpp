#pragma once
#include "std_libs.hpp"

class Event
{
private:
    string time;
    size_t event_id;
    string client_name;
    size_t table_number;
public:

    Event()
    {
        this->time = "00:00";
        this->client_name = "";
    }
    
    Event(const Event& event)
    {
        this->time = event.time;
        this->event_id = event.event_id;
        this->client_name = event.client_name;
        this->table_number = event.table_number;
    }

    string get_time() { return time; }
    string get_client_name() { return client_name; }
    size_t get_event_id() { return event_id; }
    size_t get_table_number() { return table_number; }

    void set_time(const string& time) {
        this->time = time;
    }

    void set_client_name(const string& client_name) {
        this->client_name = client_name;
    }

    void set_event_id(const size_t& event_id) {
        this->event_id = event_id;
    }

    void set_table_number(const size_t& table_number) {
        this->table_number = table_number;
    }
};