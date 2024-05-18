#pragma once
#include "table.hpp"

struct ComputerClub
{
    size_t table_count;         // Общее количество столов
    size_t price_per_hour;      // Цена за час
    string start_time;          // Время начала работы
    string end_time;            // Время окончания работы
    
    list<string> clients;       // Имена клиентов, которые сели за стол
    list<string> client_queue;  // Имена клиентов в очереди
    vector<Table> tables;       // Столы
};

extern ComputerClub club;