#pragma once
#include "std_libs.hpp"
#include "exception.hpp"

class Event
{
private:
    string time;
    size_t event_id;
    string client_name;
    size_t table_number;
public:
    
    void parse_event_line(const string& event_line) {
        std::regex event_regex("(\\d\\d:\\d\\d) (\\d+) (client\\d+)( )?(\\d+)?");
        std::smatch match;

        if (std::regex_match(event_line, match, event_regex)) {
            time = match[1];
            event_id = std::stoi(match[2]);
            client_name = match[3];
            if (match[5] != "") {
                table_number = std::stoi(match[5]);
            }
        } else {
            throw Exception(event_line);
        }
    }

    string get_time() { return time; }
    string get_client_name() { return client_name; }
    size_t get_event_id() { return event_id; }
    size_t get_table_number() { return table_number; }
};