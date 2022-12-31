#include "essentials.h"
#include "stopwatch.c"
#include "countdown.c"

int main()
{
    clear();
    color();
    menu();
    return 0;
}
void menu()
{
    clear();
    set_cursor(Y+3, X); //set the cursor position.
    printf("<");
    for (int i = 0; i <= 80; i++)
    {
        printf("%c", 0xB1);
        if (i == 40)
        {
            printf(" MAIN MENU ");
            continue;
        }
    }
    printf(">");

    set_cursor(Y+6, X+2);
    printf("This program contains a stopwatch and a countdown timer.");
    set_cursor(Y+6, X+4);
    printf(" %c Select 1 from the options below!.", 0xAF);

    set_cursor(Y+9, X+6);
    printf("1.) StopWatch");
    set_cursor(Y+9, X+8);
    printf("2.) Countdown Timer.");

    options:
    set_cursor(Y+9, X+10);
    switch (getch())
    {
        case '1' :
            stopwatch();
            break;
        case '2' :
            countdown();
            break;
        case CTRL('c') :
        case CTRL('q') :
            exit(0);
        default :
            goto options;
    }
}