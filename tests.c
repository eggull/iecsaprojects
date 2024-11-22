#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}
void a_w(int i_y, int i_x){ // The character moves on the positive y-axis
        gotoxy(i_x, i_y+1); printf(" ");
        gotoxy(i_x, i_y); printf("%c", 219);
        fflush(stdout);
}
void a_a(int i_y, int i_x){ 
        gotoxy(i_x+1, i_y); printf(" ");
        gotoxy(i_x, i_y);printf("\1");
        fflush(stdout);
}
void a_s(int i_y, int i_x){
        gotoxy(i_x, i_y-1); printf(" ");
        gotoxy(i_x, i_y);printf("\1");
        fflush(stdout);
}
void a_d(int i_y, int i_x){
        gotoxy(i_x-1, i_y); printf(" ");
        gotoxy(i_x, i_y);printf("\1");
        fflush(stdout);
}
void objects(int length, int width){ //We can't use for, bcs it affects all console log, so, we need to write and re-write it.
    int y = 0, x = 0, r;
    r = 1+ rand() % 5;
    switch (r)
    {
    case 1: //UP-DOWN
        y = 0;
    while(y < width)
    {
        y++;
        gotoxy(x, y); printf("*");
        usleep(50000);
        gotoxy(x, y); printf(" ");
        fflush(stdout);
    }
        break;
    case 2: //DOWN-UP
        y = width;
    while(y > 0)
    {
        y--;
        gotoxy(x, y); printf("*");
        usleep(50000);
        gotoxy(x, y); printf(" ");
        fflush(stdout);
    }
        break;
    case 3: //LEFT-RIGHT
        x = 0;
    while(x < length)
    {
        x++;
        gotoxy(x, y); printf("*");
        usleep(50000);
        gotoxy(x, y); printf(" ");
        fflush(stdout);
    }
        break;
    case 4: //RIGHT-LEFT
        x = length;
    while(x > 0)
    {
        x--;
        gotoxy(x, y); printf("*");
        usleep(50000);
        gotoxy(x, y); printf(" ");
        fflush(stdout);
    }
        break;
    default:
        break;
    }
  }
void main(){
int length=20, width=20, i_x=10, i_y=10;
while(1){
objects(length, width);
char arrow;
    if(_kbhit()) //Fix the getch, when press a letter, for example; a after w, a is the new getch letter, but u held down the letter w and u stop pressing the letter a, w must be the new getch letter, but getch isn't reading the letter w.
    {
        arrow = _getch();
/*
        arrow_1 = _getch(); //This will be the extra character (define the diag)
        if(arrow == 'w')
        {
            last_arrow = 'w';
        }
        if(arrow == 'a')
        {
            last_arrow = 'a';
        }
        if(arrow == 's')
        {
            last_arrow = 's';
        }
        if(arrow == 'd')
        {
            last_arrow = 'd';
        }
*/
    switch (arrow)
    {
    case 'w':
    if (i_y > 0)
    {
        usleep(1000);
        i_y--;
        a_w(i_y,i_x);
    }
        break;
    case 'a':
    if (i_x > 0)
    {
        i_x--;
        a_a(i_y,i_x);
        usleep(5000);
    }
        break;
    case 's':
    if (i_y < 200)
    {
        i_y++;
        a_s(i_y,i_x);
        usleep(5000);
    }
        break;
    case 'd':
    
    if (i_x < 200)
    {
        i_x++;
        a_d(i_y,i_x);
        usleep(1000);
    }
        break;

    /*case 'p':
    if (i_x < 100 && i_y >0)
    {
        i_x++;
        i_y--;
        a_wd(i_y,i_x);
        usleep(1000);
    }
        break;*/
    default:
        break;
    }
  }
}
}