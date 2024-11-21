/* This final project is for the asignature progamation, we scripted a algoritms from a minigame called "Iecsaroids"

The game has a fun theme where the character can move freely around the map but will constantly be hit by objects that can knock him down. If they touch him, he loses.
The speed of the objects and the time are proportional.

1- Lets do the movement player with WASD W(UP, ANIMATION UP), A(LEFT, ANIMATION LEFT), S(DOWN, ANIMATION DOWN), D(RIGHT, ANIMATION RIGHT)

2- Lets create the objects, each object only have 1 direction of movement.

3- Lets create the proportional speed of the objects with the time

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
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
        gotoxy(i_x, i_y); printf("%c", 219);
        gotoxy(i_x, i_y+1); printf(" ");
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
void a_wd(int i_y, int i_x){
        gotoxy(i_x-1, i_y+1); printf(" ");
        gotoxy(i_x, i_y);printf("\1");
        fflush(stdout);
}
void character(){

}
void object_1(int i_x){ //Identificate the position of the client,
        int x,y;
        x=i_x;
        y++;
        gotoxy(x, y-1); printf(" ");
        gotoxy(x, y);printf("\*");
        fflush(stdout);
        usleep(10000);
}
void speed(){

}
/*void a_2(char arrow_1, char arrow){
                    if(arrow_1 == 'd' && arrow == 'w')
                    {
                        arrow = 'p'; // Diag to norest
                    }
}*/
int main(){

int lenght=20, width=20, i_x=10, i_y=10;
object_1(i_x);
while(1){
char arrow, arrow_1, last_arrow;
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
    system("pause");
}


