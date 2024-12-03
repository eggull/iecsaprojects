#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>
#include <pthread.h>
pthread_t player, asteroid_1, asteroid_2 , asteroid_3, asteroid_4, asteroid_5, asteroid_6, asteroid_7, asteroid_8, obj;
int lenght=35, width=100;
int main();
void gotoxy(int x,int y)
{
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}
int random_r()
{
    srand(time(NULL));
    return rand()%9;
}
int rand_yr()
{
    srand(time(NULL));
    return (rand()%lenght) +30;
}
int rand_xr()
{
    srand(time(NULL));
    return (rand()%width) +30;
}
void asteroids_1()
{
    int v_ix, v_iy, y = 1, x = 1;
    v_ix = 2 + rand() % width;
    v_iy = 2 + rand() % lenght;
    y = 1;
    while(y < lenght)
    {
        gotoxy(v_ix, y); printf("*");
        Sleep(50);
        gotoxy(v_ix, y); printf(" ");
        y++;
    }
}
void asteroids_2()
{
    int v_ix, v_iy, y = 1, x = 1;
    v_ix = 2 + rand() % width;
    v_iy = 2 + rand() % lenght;
    y = lenght;
    while(y > 1)
    {
        gotoxy(v_ix, y); printf("*");
        Sleep(50);
        gotoxy(v_ix, y); printf(" ");
        y--;
    }
}
void asteroids_3()
{
    int v_ix, v_iy, y = 1, x = 1;
    v_ix = 2 + rand() % width;
    v_iy = 2 + rand() % lenght;
    x  = 1;
    while(x < width)
    {
        gotoxy(x, v_iy); printf("*");
        Sleep(50);
        gotoxy(x, v_iy); printf(" ");
        x++;

    }
}
void asteroids_4()
{
    int v_ix, v_iy, y = 1, x = 1;
    v_ix = 2 + rand() % width;
    v_iy = 2 + rand() % lenght;
    x = width;
    while(x > 1)
    {
        gotoxy(x, v_iy); printf("*");
        Sleep(50);
        gotoxy(x, v_iy); printf(" ");
        x--;
    }
}
void asteroids_5()
{
    int v_ix, v_iy, y = 1, x = 1;
    v_ix = 2 + rand() % width;
    v_iy = 2 + rand() % lenght;
    y = lenght;
    while(v_ix > 1 && y > 1)
    {
        gotoxy(v_ix, y); printf("*");
        Sleep(50);
        gotoxy(v_ix, y); printf(" ");
        v_ix--;
        y--;
    }
}
void asteroids_6()
{
    int v_ix, v_iy, y = 1, x = 1;
    v_ix = 2 + rand() % width;
    v_iy = 2 + rand() % lenght;
    y = 1;
    while(v_ix < width && y < lenght)
    {
        gotoxy(v_ix, y); printf("*");
        Sleep(50);
        gotoxy(v_ix, y); printf(" ");
        v_ix++;
        y++;
    }
}
void asteroids_7()
{
    int v_ix, v_iy, y = 1, x = 1;
    v_ix = 2 + rand() % width;
    v_iy = 2 + rand() % lenght;
    x = 1;
    while(x < width && v_iy > 1)
    {
        gotoxy(x, v_iy); printf("*");
        Sleep(50);
        gotoxy(x, v_iy); printf(" ");
        x++;
        v_iy--;
    }
}
void asteroids_8()
{
    int v_ix, v_iy, y = 1, x = 1;
    v_ix = 2 + rand() % width;
    v_iy = 2 + rand() % lenght;
    x = width;
    while(x > 1 && v_iy < lenght)
    {
        gotoxy(x, v_iy); printf("*");
        Sleep(50);
        gotoxy(x, v_iy); printf(" ");
        x--;
        v_iy++;
    }
}
void squar()
{
    for(int i = -1; i<=width+3; i++)
    {
        gotoxy(i,0); printf("-");
        gotoxy(i,lenght+2); printf("-");
        for(int j = -1; j <= lenght+2; j++)
        {
            gotoxy(0,j); printf("|");
            gotoxy(width+3,j); printf("|");
        }
    }
}
void character(int i_x, int i_y)
{
    int i, ix, iy;
    ix = i_x;
    iy = i_y;
    gotoxy(ix-3, iy+2);
    for(i=0; i<=2; i++)
        printf("%c", 219);
        printf("=======");
    gotoxy(ix-4, iy+1);
    for(i=0; i<=6; i++)
        printf("%c", 219);
    gotoxy(ix-2, iy);
    for(i=0; i<=9; i++)
        printf("%c", 219);
        printf("%c", 254);
    gotoxy(ix-4, iy-1);
    for(i=0; i<=6; i++)
        printf("%c", 219);
    gotoxy(ix-3, iy-2);
    for(i=0; i<=2; i++)
        printf("%c", 219);
        printf("=======");
}
void erase(int i_x, int i_y)
{
int i, ix, iy;
    ix = i_x;
    iy = i_y;
    gotoxy(ix-4, iy+2);
    for(i=0; i<=10; i++)
        printf(" ");
    gotoxy(ix-5, iy+1);
    for(i=0; i<=10; i++)
        printf(" ");
    gotoxy(ix-3, iy);
    for(i=0; i<=11; i++)
        printf(" ");
    gotoxy(ix-5, iy-1);
    for(i=0; i<=10; i++)
        printf(" ");
    gotoxy(ix-4, iy-2);
    for(i=0; i<=10; i++)
        printf(" ");
}
void a_w(int i_y, int i_x)
{ // The character moves on the positive y-axis
        gotoxy(i_x, i_y); erase(i_x,i_y+1);
        gotoxy(i_x, i_y); character(i_x,i_y);
}
void a_a(int i_y, int i_x)
{
        gotoxy(i_x, i_y); erase(i_x+1,i_y);
        gotoxy(i_x, i_y); character(i_x,i_y);
}
void a_s(int i_y, int i_x)
{
        gotoxy(i_x, i_y); erase(i_x,i_y-1);
        gotoxy(i_x, i_y); character(i_x,i_y);
}
void a_d(int i_y, int i_x)
{
        gotoxy(i_x, i_y); erase(i_x-1,i_y);
        gotoxy(i_x, i_y); character(i_x,i_y);
}
void *mov(void *game)
{
int i_x=10, i_y=10;
while(1)
{
    if(_kbhit()) //Fix the getch, when press a letter, for example; a after w, a is the new getch letter, but u held down the letter w and u stop pressing the letter a, w must be the new getch letter, but getch isn't reading the letter w.
    {
        char arrow = _getch();

    switch (arrow)
    {
    case 'w':
    if (i_y > 0)
    {
        i_y--;
        a_w(i_y,i_x);
        Sleep(50);
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
    if (i_y < lenght-1)
    {
        i_y++;
        a_s(i_y,i_x);
        Sleep(50);
    }
        break;
    case 'd':

    if (i_x < width-1)
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
}
void *as_1(void *time_1)
{
    while(1)
    {
    int r;
    r = random_r();
    switch(r)
    {
    case 1: asteroids_1(); break;
    case 2: asteroids_2(); break;
    case 3: asteroids_3(); break;
    case 4: asteroids_4(); break;
    case 5: asteroids_5(); break;
    case 6: asteroids_6(); break;
    case 7: asteroids_7(); break;
    case 8: asteroids_8(); break;
    default:break;
    }
    }
}
void *goal()
{
    int x_r, y_r;
    x_r = rand_xr(); y_r = rand_yr();
    gotoxy(x_r, y_r);printf("%c", 178);
    if()
    {
        square();
    }
}
int main()
{
    srand(time(NULL));
    squar();
    pthread_create(&player, NULL, &mov, NULL);
    pthread_create(&obj, NULL, &goal, NULL);
    pthread_create(&asteroid_1, NULL, &as_1, NULL);
    pthread_join(obj, NULL);
    pthread_join(player, NULL);
    pthread_join(asteroid_1, NULL);
}
