//
// Created by Mr Mas on 01.01.2023.
//
#include "essentials.h"

void countdown()
{
    main_two:
    clear();                        //Clear terminal
    set_cursor(Y+3, X);       //Set console cursor position & print the banner
    printf("<");
    for (int i = 0; i <= 74; i++)
    {
        printf("%c", 0xB1);
        if (i == 37)
        {
            printf(" COUNTDOWN TIMER ");
            continue;
        }
    }
    printf(">");

    millisecond = 0;
    set_cursor(Y+6, X+2); //Set cursor position
    printf("%c Enter the time in Hour :: Minute :: Seconds : ", 0xAF);
    scanf("%d %d %d", &hour, &minute, &second);


    while (1)
    {
        //Runs until all condition within the loop is satisfied.
        set_cursor(Y+18, X+6);
        printf("%02d : %02d : %02d : %02d\r", hour, minute, second, millisecond);
        fflush(stdout);  // flush the output buffer

        //Instructions.
        set_cursor(Y+6, X+12);
        printf("\xAF Press 'P' to pause the timer!...");
        set_cursor(Y+6, X+14);
        printf("\xAF If the timer is paused, press 'R' to reset it or any other key to go back to the main menu!...");

        set_cursor(Y+18, X+8);
        delay(1); // pause for a second
        if (kbhit()){ //Detects if a key is pressed
            char qh = getch();
            if (qh == 'p' || qh == 'P'){ //pauses if P is pressed
                char xh = getch();
                if (xh == 'r' || xh == 'R') //Resets the timer if R is pressed while paused
                {
                    clear(); //clear terminal
                    goto main_two;
                }
                continue;
            }
        }
        if (millisecond == 0)
        {
            if (second == 0)
            {
                if (minute == 0)
                {
                    if (hour == 0)
                    {
                        set_cursor(Y+39, X+12);
                        del(39);
                        set_cursor(Y+101, X+14);
                        del(101);
                        set_cursor(Y+12, X+10);
                        printf("The timer is up!...");
                        set_cursor(Y+12, X+12);
                        printf("Press 'R' to restart the timer or any key to go back to the main menu.");
                        set_cursor(Y+12, X+14);
                        if (getch() == 'r' || getch() == 'R')
                        {
                            goto main_two;
                        }
                        else
                        {
                            menu();
                            break;
                        }
                    }
                    hour--;
                    minute = 59;
                }
                else
                {
                    minute--;
                }
                second = 59;
            }
            else
            {
                second--;
            }
            millisecond = 59;
        }
        millisecond--;
    }
}