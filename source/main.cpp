#include "std_libs.hpp"
#include "event.hpp"
#include "file.hpp"
#include "exception.hpp"
#include "validator.hpp"

struct ComputerClub
{
    size_t table_count;
    size_t price_per_hour;
    string start_time;
    string end_time;
    list<Event> events;
} club;



int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        File file(argv[1]);
        Validator validator;
        
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

                club.events.push_back(event);
            }



            // Вывод прочитанных данных для проверки
            std::cout << "N: " << club.table_count << std::endl;
            std::cout << "Start time: " <<  club.start_time<< std::endl;
            std::cout << "End time: " << club.end_time << std::endl;
            std::cout << "Price: " << club.price_per_hour << std::endl;
            std::cout << "Events:" << std::endl;
            for (auto event : club.events) {
                std::cout << event.get_time() << " " << event.get_event_id() << " " << event.get_client_name() << " " << event.get_table_number() << std::endl;
            }

        }
    }
    else
    {
        cerr << "[ERROR]: Missing arguments" << endl; 
    }
    return 0;
}