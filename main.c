#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
//#include <fcnt1.h>
#include <stdio.h>
//#include <ctime.h>

struct date
{
    unsigned day;
    unsigned month;
};
struct time
{
    int hour;
    int minute;
};
struct event
{
    struct date d;
    struct time t;
    char* name;
    char* description;
};

struct event* events;
FILE *fp;

int main(int argc, const char* argv[])
{
    if (argc < 2)
    {
        printf("No options selected. Please type './a.out help' for possible options.\n");
        return 0;
    }
    char command = *(argv[1]);
    char input = '\0';
    fp = fopen("sched.txt", "a+");
    switch(command)
    {
        //view events
        case('v'):
            //displayText();
            printf("test\n");
            break;
            //new event
        case('a'):
            newEvent();
            //way to add new event
            break;
        case('s'):
            //way to switch order
            break;
        case('e'):
            //way to edit existing event
            break;
        case('d'):
            //deletes an event
            break;
        case('c'):
            printf("Deleting all saved data. Are you sure? (Y,N)\n");
            scanf("%c", &input);
            //ERROR HERE DEBUG for Default
            switch (input)
            {
                case('y'):
                    if (clearData() == 0)
                        printf("Successfully cleared saved data.\n");
                    else
                        printf("unlink error.\n");
                    fclose(fp);
                    return 0;
                case('n'):
                    fclose(fp);
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
    fclose(fp);
    return(0);
}

//TODO: clearData(), newEvent()

int eventLooper(int (*f) (void), char input)
{
    switch (input)
    {
        //case('\0'):
        case('y'):
            (*f)();
            return 0;
        case('n'):
            return 0;
        default:
            printf("Please enter a valid option.\n");
            scanf(" %c", &input);
            eventLooper((*f), input);
            break;
    }
}
void setEvent(char input [256])
{
    fwrite(input, sizeof(input[0]), sizeof(input)/sizeof(input[0]), fp);
}
void getEvents(struct event* buffer)
{
}
int newEvent()
{
    printf("Please enter the name and time of the event in the following order : \"date | time | name\"\n");
    char input [256], loop = 0;
    scanf("%s", input);
    setEvent(input);
    printf("Add another event? (Y,N)\n");
    scanf(" %c", &loop);
    eventLooper(newEvent, loop);
}
int clearData()
{
    char file[] = "sched.txt";
    return unlink(file);
}
