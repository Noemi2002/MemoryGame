#include <curses.h>
#include <ncurses.h>
#include <unistd.h>

using namespace std;

typedef struct MEMPACKED
{
char name1[20];
unsigned long MemTotal;
}MEM_OCCUPY;

void get_meminfo(MEM_OCCUPY *lpMemory)
{
    FILE *fd; // Object file
    char buff[128]; // Carga la información desde del archivo
    fd = fopen("/proc/meminfo", "r"); // Lee el uso de la memoria desde el archivo

    initscr(); // inicializa la ventana
    clear();

    for(int i = 0; i < 45; i++) // Lee el archivo y lo muestra en pantalla
    {
        fgets(buff, sizeof(buff), fd);
        sscanf(buff, "%s %lu ", lpMemory->name1, &lpMemory->MemTotal);
        printw(buff);
        refresh(); // refresca la ventana
    }

    fclose(fd); // Cierra el archivo
    getch(); // Pausa el output mostrado en pantalla
    sleep(2); // Duerme uno segundos
    endwin(); // desasigna memoria y finaliza ncurses
}

int main(int argc, char *argv[])
{
    MEM_OCCUPY *lpMemory;
    for(int i = 0; i < 10; i++)
    {
        get_meminfo(lpMemory);
    }
    return 0;
}
