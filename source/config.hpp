#pragma once
#include "table.hpp"

struct ComputerClub
{
    size_t table_count;
    size_t price_per_hour;
    string start_time;
    string end_time;
    
    list<string> clients;
    list<string> client_queue;
    vector<Table> tables;
};

extern ComputerClub club;