#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <pthread.h>
pthread_t player, asteroid_1, asteroid_2 , asteroid_3, asteroid_4, asteroid_5, asteroid_6, asteroid_7, asteroid_8, cls;
int lenght=48, width=232;
void gotoxy(int x,int y)
{
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}
int random()
{   
    srand(time(NULL));
    return rand()%15 +28;
}
void asteroids_1()
{   
    int v_iy1, x = width;
    v_iy1 = random(); 
    while(x > 1)
    {
        gotoxy(x, v_iy1); printf("*");
        Sleep(25);
        gotoxy(x, v_iy1); printf("              ");
        x--;
    }
}
void asteroids_2()
{   
    Sleep(500);
    int v_iy2, x = width;
    v_iy2 =random();  
    while(x > 1)
    {
        gotoxy(x, v_iy2); printf("*");
        Sleep(13);
        gotoxy(x, v_iy2); printf("              ");
        x--;
    }
}
void asteroids_3()
{   
    Sleep(1000);
    int v_iy3, x = width;
    v_iy3 =random(); 
    while(x > 1)
    {
        gotoxy(x, v_iy3); printf("*");
        Sleep(25);
        gotoxy(x, v_iy3); printf("            ");
        x--;
    }
}
void asteroids_4()
{   
    Sleep(1500);
    int v_iy4, x = width;
    v_iy4 =random(); 
    while(x > 1)
    {
        gotoxy(x, v_iy4); printf("*");
        Sleep(20);
        gotoxy(x, v_iy4); printf("            ");
        x--;
    }
}
void asteroids_5()
{   
    Sleep(2000);
    int v_iy5, x = width;
    v_iy5 =random(); 
    while(x > 1)
    {
        gotoxy(x, v_iy5); printf("*");
        Sleep(18);
        gotoxy(x, v_iy5); printf("              ");
        x--;
    }
}
void asteroids_6()
{   
    Sleep(2500);
    int v_iy6, x = width;
    v_iy6 =random(); 
    while(x > 1)
    {
        gotoxy(x, v_iy6); printf("*");
        Sleep(17);
        gotoxy(x, v_iy6); printf("             ");
        x--;
    }
}
void asteroids_7()
{   
    Sleep(3000);
    int v_iy7, x = width;
    v_iy7 =random(); 
    while(x > 1)
    {
        gotoxy(x, v_iy7); printf("*");
        Sleep(16);
        gotoxy(x, v_iy7); printf("           ");
        x--;
    }
}
void asteroids_8()
{   
    Sleep(3500);
    int v_iy8, x = width;
    v_iy8 =random(); 
    while(x > 1)
    {
        gotoxy(x, v_iy8); printf("*");
        Sleep(10);
        gotoxy(x, v_iy8); printf("             ");
        x--;
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
{
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
int i_x=10, i_y=35;
while(1)
{
    if(_kbhit()) 
    {
        char arrow = _getch();

    switch (arrow)
    {
    case 'w':
    if (i_y > 30)
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
    if (i_y < lenght-3)
    {
        i_y++;
        a_s(i_y,i_x);
    }
        break;
    case 'd':

    if (i_x < width)
    {
        i_x++;
        a_d(i_y,i_x);
    }
        break;
    default:
        break;
    }
    Sleep(50);
  }
}
}
void *as_1()
{
    while(1)
    {
    asteroids_1();
    }
}
void *as_2()
{
    while(1)
    {
    asteroids_2();

    }
}
void *as_3()
{
    while(1)
    {
    asteroids_3();
    }
}
void *as_4()
{
    while(1)
    {
    asteroids_4();
    }
}
void *as_5()
{
    while(1)
    {
    asteroids_5();
    }
}
void *as_6()
{
    while(1)
    {
    asteroids_6();
    }
}
void *as_7()
{
    while(1)
    {
    asteroids_7();
    }
}
void *as_8()
{
    while(1)
    {
    asteroids_8();
    }
}
void menu()
{
    for(int i = -1; i < width; i++)
    {
        gotoxy(i,27); printf("-");
        gotoxy(i,48); printf("-");
    }
    gotoxy(width,26); printf("META");
}
int main()
{   
    Sleep(1500);
    menu();
    pthread_create(&player, NULL, &mov, NULL);
    pthread_create(&asteroid_1, NULL, &as_1, NULL);
    pthread_create(&asteroid_2, NULL, &as_2, NULL);
    pthread_create(&asteroid_3, NULL, &as_3, NULL);
    pthread_create(&asteroid_4, NULL, &as_4, NULL);
    pthread_create(&asteroid_5, NULL, &as_5, NULL);
    pthread_create(&asteroid_6, NULL, &as_6, NULL);
    pthread_create(&asteroid_7, NULL, &as_7, NULL);
    pthread_create(&asteroid_8, NULL, &as_8, NULL);
    pthread_join(player, NULL);
    pthread_join(asteroid_1, NULL);
    pthread_join(asteroid_2, NULL);
    pthread_join(asteroid_3, NULL);
    pthread_join(asteroid_4, NULL);
    pthread_join(asteroid_5, NULL);
    pthread_join(asteroid_6, NULL);
    pthread_join(asteroid_7, NULL);
    pthread_join(asteroid_8, NULL);
}

