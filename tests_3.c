#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

int lenght = 60, width = 150;

// Función gotoxy para mover el cursor a una posición específica
void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

// Función que imprime valores infinitamente a lo largo de la pantalla en una dirección vertical
void print_vertical()
{
    int x = 10;
    int y = 1;
    while (1) // Bucle infinito
    {
        gotoxy(x, y); // Mover el cursor
        printf("Valor: %d", y); // Imprimir el valor
        y++; // Mover la posición vertical hacia abajo

        if (y > lenght) y = 1; // Reiniciar la posición vertical cuando se llega al final de la pantalla

        Sleep(100); // Espera de 100ms
    }
}

// Función que imprime valores infinitamente a lo largo de la pantalla en una dirección horizontal
void print_horizontal()
{
    int x = 1;
    int y = 10;
    while (1) // Bucle infinito
    {
        gotoxy(x, y); // Mover el cursor
        printf("Valor: %d", x); // Imprimir el valor
        x++; // Mover la posición horizontal hacia la derecha

        if (x > width) x = 1; // Reiniciar la posición horizontal cuando se llega al final de la pantalla

        Sleep(100); // Espera de 100ms
    }
}

// Función que imprime valores en una dirección diagonal
void print_diagonal()
{
    int x = 1;
    int y = 1;
    while (1) // Bucle infinito
    {
        gotoxy(x, y); // Mover el cursor
        printf("Valor: %d", x); // Imprimir el valor
        x++; // Mover la posición horizontal hacia la derecha
        y++; // Mover la posición vertical hacia abajo

        if (x > width) x = 1; // Reiniciar la posición horizontal cuando se llega al final de la pantalla
        if (y > lenght) y = 1; // Reiniciar la posición vertical cuando se llega al final de la pantalla

        Sleep(100); // Espera de 100ms
    }
}

// Función que imprime valores en un patrón de zig-zag (horizontal y vertical alternado)
void print_zigzag()
{
    int x = 1;
    int y = 1;
    int direction = 1; // Dirección del zig-zag (1 = hacia la derecha, -1 = hacia la izquierda)

    while (1) // Bucle infinito
    {
        gotoxy(x, y); // Mover el cursor
        printf("Valor: %d", x); // Imprimir el valor

        if (direction == 1)
        {
            x++; // Mover la posición horizontal hacia la derecha
            if (x > width) direction = -1; // Cambiar la dirección cuando llegamos al borde derecho
        }
        else
        {
            x--; // Mover la posición horizontal hacia la izquierda
            if (x < 1) direction = 1; // Cambiar la dirección cuando llegamos al borde izquierdo
        }

        y++; // Mover la posición vertical hacia abajo

        if (y > lenght) y = 1; // Reiniciar la posición vertical cuando se llega al final de la pantalla

        Sleep(100); // Espera de 100ms
    }
}

int main()
{
    // Crear múltiples hilos para que las funciones impriman en paralelo
    // En lugar de imprimir solo en la consola principal, se pueden usar pthreads para crear hilos si se requiere imprimir en diferentes partes de la pantalla.

    // Descomentar estas líneas si deseas usar varios hilos en un entorno compatible con pthreads.
    // pthread_t t1, t2, t3, t4;
    // pthread_create(&t1, NULL, (void*)print_vertical, NULL);
    // pthread_create(&t2, NULL, (void*)print_horizontal, NULL);
    // pthread_create(&t3, NULL, (void*)print_diagonal, NULL);
    // pthread_create(&t4, NULL, (void*)print_zigzag, NULL);

    // Mantener el programa principal en ejecución
    // pthread_join(t1, NULL);
    // pthread_join(t2, NULL);
    // pthread_join(t3, NULL);
    // pthread_join(t4, NULL);

    // En este caso, ejecutamos las funciones en el hilo principal para simplificar
    print_vertical();    // Imprime valores verticalmente
    print_horizontal();  // Imprime valores horizontalmente
    print_diagonal();    // Imprime valores diagonalmente
    print_zigzag();      // Imprime valores en zig-zag

    return 0;
}
