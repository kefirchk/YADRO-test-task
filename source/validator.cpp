#include "validator.hpp"

bool Validator::is_number(string line, size_t& number)
{
    std::regex regex("(\\d+)");
    std::smatch match;

    if (std::regex_match(line, match, regex)) {
        number = stoi(match[1]);
        return true;
    }
    return false;
}

bool Validator::is_two_time(string line, string& time_1, string& time_2)
{
    std::regex regex("(\\d\\d:\\d\\d) (\\d\\d:\\d\\d)");
    std::smatch match;

    if (std::regex_match(line, match, regex)) {
        time_1 = match[1];
        time_2 = match[2];
        return true;
    }
    return false;
}

bool Validator::is_event(string line, Event& event)
{
    std::regex regex("(\\d\\d:\\d\\d) (\\d+) (client\\d+)( (\\d+))?");
    std::smatch match;

    if (std::regex_match(line, match, regex)) {
        event.set_time(match[1]);
        event.set_event_id(stoi(match[2]));
        event.set_client_name(match[3]);
        if (match[5] != "") {
            event.set_table_number(std::stoi(match[5]));
        } else {
            event.set_table_number(0);
        }
        return true;
    }
    return false;
}