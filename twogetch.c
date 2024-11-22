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
    }
}

/*
void a_w(int i_y, int i_x){ // The character moves on the positive y-axis
        gotoxy(i_x, i_y); printf("%c", 219);
        gotoxy(i_x, i_y+1); printf(" ");
        fflush(stdout);
}
void a_a(int i_y, int i_x){ 
        gotoxy(i_x, i_y);printf("\1");
        gotoxy(i_x+1, i_y); printf(" ");
        fflush(stdout);
}
void a_s(int i_y, int i_x){
        gotoxy(i_x, i_y);printf("\1");
        gotoxy(i_x, i_y-1); printf(" ");
        fflush(stdout);
}
void a_d(int i_y, int i_x){
        gotoxy(i_x, i_y);printf("\1");
        gotoxy(i_x-1, i_y); printf(" ");
        fflush(stdout);
}
void a_wd(int i_y, int i_x){
        gotoxy(i_x, i_y);printf("\1");
        gotoxy(i_x-1, i_y+1); printf(" ");
        fflush(stdout);
}
void w(int i_x, int i_y){
    if (i_y > 0)
    {
        usleep(1000);
        i_y--;
        a_w(i_y,i_x);
    }
}
void a(int i_x, int i_y){
    if (i_x > 0)
    {
        i_x--;
        a_a(i_y,i_x);
        usleep(5000);
    }
}
void s(int i_x, int i_y){
    if (i_y < 200)
    {
        i_y++;
        a_s(i_y,i_x);
        usleep(5000);
    }
}
void d(int i_x, int i_y){
    if (i_x < 200)
    {
        i_x++;
        a_d(i_y,i_x);
        usleep(1000);
    }
}

/*
void objects(int r, int y, int x, int length, int width){
    r = 1+ rand() % 5;
    switch (r)
    {
    case 1: //UP-DOWN
        for (y = 0; y <= width; y++)
    {
        gotoxy(x, y); printf("*");
        usleep(50000);
        gotoxy(x, y); printf(" ");
        fflush(stdout);
    }
        y = 0;
        break;
    case 2: //DOWN-UP
        for (y = width; y >= 0; y--)
    {
        gotoxy(x, y); printf("*");
        usleep(50000);
        gotoxy(x, y); printf(" ");
        fflush(stdout);
    }
        y = width;
        break;
    case 3: //LEFT-RIGHT
        for (x = 0; x < length; x++)
    {
        gotoxy(x, y); printf("*");
        usleep(50000);
        gotoxy(x, y); printf(" ");
        fflush(stdout);
    }
        x = 0;
        break;
    case 4: //RIGHT-LEFT
        for (x = length; x >= 0; x--)
    {
        gotoxy(x, y); printf("*");
        usleep(50000);
        gotoxy(x, y); printf(" ");
        fflush(stdout);
    }
        x = length;
        break;
    default:
        break;
    }
}

int main(){
srand(time(NULL));
int length = 20, width = 20, y = 0, x = 0, r, i_x = 10, i_y = 10;
while(1){
char arrow;
    if(_kbhit()) //Fix the getch, when press a letter, for example; a after w, a is the new getch letter, but u held down the letter w and u stop pressing the letter a, w must be the new getch letter, but getch isn't reading the letter w.
    {
        arrow = _getch();
switch (arrow)
    {
    case 'w':
    w(i_x, i_y);
        break;
    case 'a':
    a(i_x, i_y);
        break;
    case 's':
    s(i_x, i_y);
        break;
    case 'd':
    d(i_x, i_y);
        break;
    default:
        break;
    }
   // objects(r, y, x, length, width);
    }
  } 
}

/*
 int main(){
srand(time(NULL));
int length = 20, width = 20, y = 0, x = 0, r;
while(1){
    r = 1+ rand() % 5;
    switch (r)
    {
    case 1: //UP-DOWN
        for (y = 0; y <= width; y++)
    {
        gotoxy(x, y); printf("*");
        usleep(50000);
        gotoxy(x, y); printf(" ");
        fflush(stdout);
    }
        y = 0;
        break;
    case 2: //DOWN-UP
        for (y = width; y >= 0; y--)
    {
        gotoxy(x, y); printf("*");
        usleep(50000);
        gotoxy(x, y); printf(" ");
        fflush(stdout);
    }
        y = width;
        break;
    case 3: //LEFT-RIGHT
        for (x = 0; x < length; x++)
    {
        gotoxy(x, y); printf("*");
        usleep(50000);
        gotoxy(x, y); printf(" ");
        fflush(stdout);
    }
        x = 0;
        break;
    case 4: //RIGHT-LEFT
        for (x = length; x >= 0; x--)
    {
        gotoxy(x, y); printf("*");
        usleep(50000);
        gotoxy(x, y); printf(" ");
        fflush(stdout);
    }
        x = length;
        break;
    default:
        break;
    }
    }
   }
*/

  /*  int main(){
        char arrow, arrow_1;
        while(1){
            if(_kbhit()){
                arrow = _getch();
                    printf("%c\t", arrow);
                arrow_1 = _getch();
                    printf("%c\t", arrow_1);
                    if(arrow_1 == 'd' && arrow == 'w') //por un instante se leen las 2 letras, pero cuando esto discrepa, tiende a solo usar una funcion getch, por lo tanto, debe guardarse un valor getch simultaneamente. Leer los valores uno a uno pero esto alternando su lectura, que estará definida con una velocidad, esta velocidad tiene que ser mínima.
                    {
                        arrow = 'p'; // Diag to norest
                    }
            printf("%c", arrow);
            }
        }
        system("pause");
    }*/ //Una forma de hacerlo
/*int main(){
    char arrow, arrow_1;
        while(1){
            if(_kbhit()){

            arrow = _getch();

            printf("arrow =%c\t", arrow);

            printf("arrow_1 =%c\n", arrow_1);
                    if(arrow_1 == 'd' && arrow == 'w' && _getch() == 'd' || _getch() == 'w') //por un instante se leen las 2 letras, pero cuando esto discrepa, tiende a solo usar una funcion getch, por lo tanto, debe guardarse un valor getch simultaneamente. Leer los valores uno a uno pero esto alternando su lectura, que estará definida con una velocidad, esta velocidad tiene que ser mínima.
                    {
                        arrow = 'p'; // Diag to norest
                    }
            printf("%c\n", arrow);
            }
        }
        system("pause");
    }*/