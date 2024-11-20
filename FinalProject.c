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
void a_a(){

}
void a_s(){

}
void a_d(){

}
void a_wa(){

}
void a_wd(){

}
void a_sd(){

}
void a_sa(){

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
        a_a();
        break;

    case 's':
        a_s();
        break;

    case 'd':
        a_d();
        break;

    case 'wa':
        a_wa();
        break;

    case 'wd':
        a_wd();
        break;

    case 'sd':
        a_sd();
        break;

    case 'sa':
        a_sa();
        break;

    default:
        break;
    }
  }
}
    system("pause");
}




    
    
