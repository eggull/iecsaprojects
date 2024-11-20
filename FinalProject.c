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
        gotoxy(i_x, i_y+1); printf(" ");
        gotoxy(i_x, i_y);printf("*");
        usleep(80000);
}
void a_a(int i_y, int i_x){
        gotoxy(i_x+1, i_y); printf(" ");
        gotoxy(i_x, i_y);printf("*");
        usleep(80000);
}
void a_s(int i_y, int i_x){
        gotoxy(i_x, i_y-1); printf(" ");
        gotoxy(i_x, i_y);printf("*");
        usleep(80000);
}
void a_d(int i_y, int i_x){
        gotoxy(i_x-1, i_y); printf(" ");
        gotoxy(i_x, i_y);printf("*");
        usleep(80000);
}
void object(){

}
void speed(){

}
int main(){

int lenght=20, width=20, i_x=10, i_y=10;

while(1){
char arrow;
    if(_kbhit()){
       arrow = _getch();
    switch (arrow)
    {
    case 'w':
    if (i_y > 0)
    {
        i_y--;
        a_w(i_y,i_x);
    }
        break;

    case 'a':
    if (i_x > 0)
    {
        i_x--;
        a_a(i_y,i_x);
    }
        break;

    case 's':
    if (i_y < 100)
    {
        i_y++;
        a_s(i_y,i_x);
    }
        break;

    case 'd':
    if (i_x < 100)
    {
        i_x++;
        a_d(i_y,i_x);
    }
        break;

    default:
        break;
    }
  }
}
    system("pause");
}



    
    
