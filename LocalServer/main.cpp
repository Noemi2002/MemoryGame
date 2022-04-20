#include "widget.h"
#include <curses.h>
#include <ncurses.h>
#include <unistd.h>
#include <QApplication>
#include <localserver.h>

/*using namespace std;

typedef struct MEMPACKED
{
char name1[20];
unsigned long MemTotal;
}MEM_OCCUPY;

void get_meminfo(MEM_OCCUPY *lpMemory)
{
    FILE *fd; // Object file
    char buff[128]; // Load info from file
    //fd = fopen("/proc/self/stat", "r"); // Read memory usage File
    fd = fopen("/proc/meminfo", "r"); // Read memory usage File

    initscr(); // init screen and sets up screen
    clear();

    for(int i = 0; i < 45; i++) // Read file info and prints in screen
    {
        fgets(buff, sizeof(buff), fd);
        //sscanf(buff, "%s %lu ", lpMemory->name1, &lpMemory->MemTotal);
        printw(buff);
        refresh(); // refreshes the screen
    }

    fclose(fd); // Close File
    getch(); // pause the screen output
    sleep(2); // Sleep time in seconds
    endwin(); // deallocates memory and ends ncurses
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Widget ventana;
    ventana.show();
    //QObject *parent = 0;
    //LocalServer *ptrLS = new LocalServer(parent);
    MEM_OCCUPY *lpMemory;
    for(int i = 0; i < 10; i++) // Read file info and prints in screen
    {
        get_meminfo(lpMemory);
    }
    return a.exec();
}*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Widget ventana;
    ventana.show();

    return a.exec();
}
