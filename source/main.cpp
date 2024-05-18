#include "std_libs.hpp"
#include "event.hpp"
#include "file.hpp"
#include "exception.hpp"
#include "client.hpp"
#include "table.hpp"

struct ComputerClub
{
    unsigned int table_count;
    unsigned int price_per_hour;
    string start_time;
    string end_time;
    list<Event> events;
};

int main(int argc, char* argv[])
{
    cout <<  "Argc: " << argc << endl;
    for (int i = 0; i < argc; ++i)
    {
        cout << argv[i] << endl;
    }
    cout << endl;
    return 0;
}