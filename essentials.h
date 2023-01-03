//
// Created by MrMas on 01.01.2023.
//

#ifndef STOPWATCH_AND_COUNTDOWN_TIMER_ESSENTIALS_H
#define STOPWATCH_AND_COUNTDOWN_TIMER_ESSENTIALS_H

#include <stdio.h>
#include <stdlib.h>
#ifdef __unix__
//checks if the code is running on unix.
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <fcntl.h>
//Function for the getch() function for unix.
extern int getch() {//getch function for unix system.
    struct termios old_tio, new_tio;
    int c;

    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

    c = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    return c;
}
#define color() system("tput setab 103; setab 34") //Set the background color to light yellow and text color to dark blue
#define clear() system("clear")                    //Clear terminal
#define delay(k) sleep(k/1000)                     //Pauses for 'n' number of seconds
int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
  
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
  
  ch = getchar();
  
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
  
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
  
  return 0;
}
#else
#include <windows.h>
#include <conio.h>
#define getch() getch()
#define color() system("COLOR E1")  //Set the background color to light yellow and text color to dark blue
#define clear() system("CLS")       //Clear console
#define delay(k) Sleep(k)           //Pauses for 'n' seconds.
#endif
#define CTRL(key) ((key) & 0x1f)
void menu();
void stopwatch();
void countdown();
int X=2, Y=26, Z=17, hour, minute, second, millisecond;
extern void set_cursor(int y, int x)
{   //function to set the cursor position.
    printf("\033[%d;%dH", x, y);
    //The X value moves the cursor horizontally/ to 'n' number of spaces
    //The Y value moves the cursor vertically
}

//macros to delete a character, Not that necessary.
#define del(n) do { \
    for (int i = 0; i < n; i++) { \
        putchar('\b'); \
        putchar(' '); \
        putchar('\b'); \
    } \
} while (0)
#endif //STOPWATCH_AND_COUNTDOWN_TIMER_ESSENTIALS_H
