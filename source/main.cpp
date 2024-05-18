#include "std_libs.hpp"
#include "event.hpp"
#include "file.hpp"
#include "exception.hpp"


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
        if(file.open() == true)
        {
            try
            {
                club.table_count = stoi(file.read_line());
                club.start_time = file.read_word();
                club.end_time = file.read_line();
                club.price_per_hour = stoi(file.read_line());
            }
            catch(Exception& ex)
            {
                cerr << "[ERROR]: " << ex.get_description() << endl;
                return -1;
            }
            catch(exception &ex)
            {
                cerr << "[ERROR]: " << ex.what() << endl;
                return -1;
            }

            while(!file.is_eof())
            {
                Event event;
                string event_line = file.read_line();
                try {
                    event.parse_event_line(event_line);                
                } catch(Exception& ex) {
                    cerr << "[ERROR]: " << ex.get_description() << endl;
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