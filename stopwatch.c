//
// Created by Mr Mas on 01.01.2023.
//
#include "essentials.h"
void stopwatch()
{
    main_one:
    clear();
    set_cursor(Y+3, X);
    printf("<");
    for (int i = 0; i <= 78; i++) {
        printf("%c", 0xB1);
        if (i == 39) {
            printf(" STOP WATCH ");
            continue;
        }
    }
    printf(">");

    hour = 0, minute = 0, second = 0, millisecond = 0;
    int lap=0, lap_hour, lap_minute, lap_second, lap_millisecond;
    char c, ch;
    set_cursor(Y+6, X+2);
    printf("%c Press any key to start the timer : ", 0xAF);

    set_cursor(Y+18, X+6);
    printf("%02d : %02d : %02d : %02d\r", hour, minute, second, millisecond);
    fflush(stdout);  // flush the output buffer

    set_cursor(Y+6, X+10);
    printf("%c Press 'P' to pause, and 'L' to lap the timer.", 0xAF);
    set_cursor(Y+6, X+12);
    printf("%c If the timer is paused, Press 'C' to continue, or 'R' to reset the timer.", 0xAF);

    set_cursor(Y+12, X+15);
    printf("%c Lap time : ", 0x1A);
    set_cursor(Y+16, X+17);
    getch();
    for (;;){  // infinite loop
        set_cursor(Y+18, X+6);
        printf("%02d : %02d : %02d : %02d\r", hour, minute, second, millisecond);
        fflush(stdout);  // flush the output buffer
        set_cursor(Y+16, Z+2);

        if (kbhit())
        {
            c = getch();
            if(c == 'l' || c == 'L')
            {
                lap_hour = hour, lap_minute = minute, lap_second = second, lap_millisecond = millisecond;
                set_cursor(Y+16, Z+=2);
                printf("Lap %d:  %02d : %02d : %02d : %02d\n", ++lap, lap_hour, lap_minute, lap_second, lap_millisecond);
                continue;
            }
            else if(c == 'p' || c == 'P'){
                ch = getch();
                if (ch == 'c' || ch == 'C')
                {
                    continue;
                }
                else if (ch == 'r' || ch == 'R')
                {
                    goto main_one;
                }
                else if (ch == 'm' || ch == 'M')
                {
                    menu();
                }
                else
                {
                    //continue;
                }
            }
            else if (c == CTRL(c))
            {
                set_cursor(Y+16,Z+=2);
                exit(0);
            }
            else
            {
                continue;
            }
        }
        delay(1);  // pause for 1 millisecond
        millisecond++;
        if (millisecond == 60)
        {
            second++;
            millisecond = 0;
        }
        if (second == 60)
        {
            minute++;
            second = 0;
        }
        if (minute == 60)
        {
            hour++;
            minute = 0;
        }
    }
    getch();
}