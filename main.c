#include <sys/types.h>
#include <sys/stat.h>
//#include <fcnt1.h>
#include <stdio.h>
//#include <ctime.h>

struct date
{
    uint8_t day;
    uint8_t month;
}
struct time
{
    int hour;
    int minute;
}
struct event
{
    date d;
    time t;
    char name[];
    char description[];
}

event events[];
int main(int argc, const char* argv[])
{
    if (argc < 2)
    {
        printf("No options selected. Please type './a.out help' for possible options.\n");
        return 0;
    }
    char command = *(argv[1]);
    char input = '\0';
    switch(command)
    {
        //view events
        case('v'):
            //displayText();
            printf("test\n");
            break;
            //new event
        case('e'):
            //way to see if add new event or switch order
            break;
        case('c'):
            printf("\nDeleting all saved data. Are you sure? (Y,N)\n");
            scanf("%c", &input);
            //ERROR HERE DEBUG for Default
            switch (input)
            {
                case('y'):
                    //clearData();
                    return 0;
                case('n'):
                    return 0;
                default:
                    printf("\nPlease enter a valid option.\n");
                    scanf("%c", &input);
            }
            break;
        case('h'):
            printf("Possible Options:\n\tv - view today's events\n\t\t v c - view calender\n\te - edit event\n\t\t e m - manage events (move their times)\n\t\t e a - add new event\n\tc - clear data\n");
            break;
        default:
            printf("Option not recognized.\n");
    }
    return(0);
}

//TODO: clearData(), newEvent()
int eventadder(int (*f) (void), char input)
{
    switch (input)
    {
        case('\0'):
        case('y'):
            return (*f)();
        case('n'):
            return(0);
        default:
            printf("Please enter a valid option.");
            scanf("%c", &input);
    }
}

int newEvent()
{
    printf("Please enter the name and time of the event in the following order : \"date | time | name\"");
    //blah
    printf("Add another event? (Y,N)");
    char input = '\0';
    scanf("%c", &input);
    eventadder(newEvent, input);
}

void getEvents(event* buffer)
{
    //blah
}

void setEvent(event e)
{
    //blah
}
