#pragma once

#include "std_libs.hpp"
#include "event.hpp"
#include "exception.hpp"
#include "config.hpp"

class EventManager
{
private:
    bool check_time_interval(string time, string start_time, string end_time);

public:
    Event process_event(Event& event, bool& is_new_event);
};