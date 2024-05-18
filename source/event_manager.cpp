#include "event_manager.hpp"

// Обработка события
Event EventManager::process_event(Event& event, bool& is_new_event)
{
    Event new_event;
    size_t id = event.get_event_id();
    string client_name = event.get_client_name();
    
    switch(id)
    {
        // Клиент пришел
        case 1:
        {
            // Клуб работает?
            string client_time = event.get_time();
            if(check_time_interval(client_time, club.start_time, club.end_time) == false) {
                throw Exception(13, "NotOpenYet");
            }

            // Клиент уже в клубе?
            auto it = std::find(club.clients.begin(), club.clients.end(), client_name);
            if (it != club.clients.end()) {
                throw Exception(13, "YouShallNotPass");
            } else {
                club.client_queue.push_back(client_name);
            }
            break;
        }

        // Клиент сел за стол
        case 2:
        {
            // Есть ли такой клиент в клубе или в очереди?
            auto it1 = std::find(club.client_queue.begin(), club.client_queue.end(), client_name);
            auto it2 = std::find(club.clients.begin(), club.clients.end(), client_name);
            if (it1 == club.client_queue.end() && it2 == club.clients.end()) {
                throw Exception(13, "ClientUnknown");
            }

            // Место занято?
            size_t table_id = event.get_table_number();
            if (club.tables[table_id - 1].is_busy() == true) {
                throw Exception(13, "PlaceIsBusy");
            } else {
                for(size_t i = 0; i < club.table_count; ++i)
                {
                    if(club.tables[i].get_client_name() == client_name)
                    {
                        // Освобождаем ранее занятый стол
                        club.tables[i].set_busy(false);
                        club.tables[i].set_client_name("");
                        club.tables[i].update_full_time(event.get_time());
                        break;
                    }
                }

                // Занимаем стол
                club.tables[table_id - 1].set_client_start_time(event.get_time());
                club.tables[table_id - 1].set_busy(true);
                club.tables[table_id - 1].set_client_name(client_name);

                // Обновляем очередь и список сидящих клиентов
                if(it1 != club.client_queue.end())
                {
                    club.client_queue.erase(it1);
                    club.clients.push_back(client_name);
                }
            }
            break;
        }

        // Клиент ожидает
        case 3:
        {
            // Поиск свободных столов
            bool free_tables = false;
            for(auto table: club.tables)
            {
                if(table.is_busy() == false)
                {
                    // Свободный стол найден!
                    free_tables = true;
                    break;
                }
            }
            if(free_tables == true)
            {
                throw Exception(13, "ICanWaitNoLonger!");
            }

            if(club.client_queue.size() > club.table_count)
            {
                // Генерация события ID 11 (Клиент ушел)
                new_event.set_client_name(client_name);
                new_event.set_time(event.get_time());
                new_event.set_event_id(11);
                new_event.set_table_number(0);
                is_new_event = true;
            } else {
                // Клиент становится в очередь, если ещё не стал
                auto it1 = std::find(club.client_queue.begin(), club.client_queue.end(), client_name);
                if (it1 == club.client_queue.end())
                    club.client_queue.push_back(client_name);
            }
            break;
        }

        // Клиент ушел
        case 4:
        {
            // Есть ли такой клиент в клубе?
            auto it = std::find(club.clients.begin(), club.clients.end(), client_name);
            if (it == club.clients.end()) {
                throw Exception(13, "ClientUnknown");
            }

            // Поиск стола, за которым сидел клиент
            for (size_t i = 0; i < club.tables.size(); ++i)
            {
                if(club.tables[i].get_client_name() == client_name)
                {
                    // Освобождение стола и учет времени работы стола
                    club.tables[i].update_full_time(event.get_time());
                    club.tables[i].set_busy(false);
                    club.tables[i].set_client_name("");
                    club.clients.remove(client_name);
                    
                    // Садим первого клиента в очереди за освободившийся стол
                    if(club.client_queue.size() > 0)
                    {
                        string client = club.client_queue.front();
                        club.client_queue.pop_front();

                        // Обновление статуса стола
                        club.tables[i].set_client_start_time(event.get_time());
                        club.tables[i].set_busy(true);
                        club.tables[i].set_client_name(client);
                        club.clients.push_back(client);

                        // Генерация события ID 12 (Клиент сел за стол)
                        new_event.set_client_name(client);
                        new_event.set_time(event.get_time());
                        new_event.set_event_id(12);
                        new_event.set_table_number(club.tables[i].get_table_id()); 
                        is_new_event = true;
                    }
                    break;
                }   
            }
            break;
        }
    }
    return new_event;
}

// Проверка на вхождение значения времени в формате XX:XX в заданный интервал
bool EventManager::check_time_interval(string time, string start_time, string end_time)
{
    // Получение часов и минут из строки времени
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));

    // Получение часов и минут начального времени
    int start_hours = stoi(start_time.substr(0, 2));
    int start_minutes = stoi(start_time.substr(3, 2));

    // Получение часов и минут конечного времени
    int end_hours = std::stoi(end_time.substr(0, 2));
    int end_minutes = std::stoi(end_time.substr(3, 2));

    // Проверка, что время находится в промежутке
    if (hours > start_hours && hours < end_hours) {
        return true;
    } else if (hours == start_hours && minutes >= start_minutes) {
        return true;
    } else if (hours == end_hours && minutes <= end_minutes) {
        return true;
    }

    return false;
}