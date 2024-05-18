#include "file.hpp"
#include "validator.hpp"
#include "event_manager.hpp"

ComputerClub club;

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        File file(argv[1]);
        Validator validator;
        list<Event> events;
        
        // Чтение файла
        if(file.open() == true)
        {
            // Чтение числа столов
            string line = file.read_line();
            bool ok;
            ok = validator.is_number(line, club.table_count);
            if(!ok) {
                cerr << "[ERROR]: " << line << endl;
                return -1;
            }
            for(size_t i = 1; i <= club.table_count; ++i)
            {
                Table table(i);
                club.tables.push_back(table);
            }

            // Чтение времени начала и окончания работы
            line = file.read_line();
            ok = validator.is_two_time(line, club.start_time, club.end_time);
            if(!ok) {
                cerr << "[ERROR]: " << line << endl;
                return -1;
            }
            
            // Чтение цены за час
            line = file.read_line();
            ok = validator.is_number(line, club.price_per_hour);
            if(!ok) {
                cerr << "[ERROR]: " << line << endl;
                return -1;
            }

            // Чтение событий
            while(!file.is_eof())
            {
                Event event;
                line = file.read_line();
                ok = validator.is_event(line, event);
                if(!ok) {
                    cerr << "[ERROR]: " << line << endl;
                    return -1;
                }
                events.push_back(event);
            }

            // Вывод начального времени
            cout << club.start_time << endl;

            // Обработка и генерация событий
            EventManager event_manager;
            bool is_new_event;
            for(auto event : events)
            {
                is_new_event = false;
                try
                {
                    cout << "---------------------------" << endl;
                    cout << "Clients: ";
                    for(auto client : club.clients)
                        cout << client << " ";
                    
                    cout << "\nClient queue: ";
                    for(auto client : club.client_queue)
                        cout << client << " ";

                    cout << "\n---------------------------" << endl;
                    for(auto table : club.tables)
                    {
                        cout << "Table ID: " << table.get_table_id() << endl;
                        cout << "Table Status: " << table.is_busy() << endl;
                        cout << "Table Client Name: " << table.get_client_name() << endl;
                    }
                    cout <<  endl << endl;

                    cout << event.get_time() << " " << event.get_event_id() << " " << event.get_client_name();
                    if(event.get_table_number() != 0)
                        cout << " " << event.get_table_number();
                    cout << endl;

                    Event new_event = event_manager.process_event(event, is_new_event);
                    if (is_new_event)
                    {
                        cout << new_event.get_time() << " " << new_event.get_event_id() << " " << new_event.get_client_name();
                        if(new_event.get_table_number() != 0)
                            cout << " " << new_event.get_table_number();
                        cout << endl;
                    }
                }
                catch (Exception& ex)
                {
                    cout << event.get_time() << " " << ex.get_id() << " " << ex.get_description() << endl;
                }
            }

            // Оставшиеся клиенты выходят из клуба (генерация события ID 11)            
            list<string> all_clients;
            all_clients.splice(all_clients.end(), club.clients);
            all_clients.splice(all_clients.end(), club.client_queue);

            // Сортировка объединенного списка клиентов
            all_clients.sort();
            
            for(auto client : all_clients)
            {
                cout << club.end_time << " " << 11 << " " << client << endl;
            }

            // Вывод времени окончания работы клуба
            cout << club.end_time << endl;

            // Вывод выручки
            for(auto table: club.tables)
            {
                // TO DO...
            }

        }
    }
    else
    {
        cerr << "[ERROR]: Missing arguments" << endl; 
    }
    return 0;
}