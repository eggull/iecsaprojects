#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// Definición de la función gotoxy para mover el cursor en la consola
void gotoxy(int x, int y) {
    HANDLE hCon;
    COORD coord;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hCon, coord);
}

int main() {
    int x = 10, y = 10; // Posición inicial del primer carácter
    int x2 = 5, y2 = 5; // Posición inicial del segundo carácter
    int vx = 1, vy = 1; // Desplazamiento constante para el segundo carácter (movimiento vectorial)

    while (1) {
        // Limpiar la consola
        system("cls");

        // Mover el primer carácter con las teclas WASD
        if (_kbhit()) { // Detecta si una tecla ha sido presionada
            int ch = _getch(); // Obtiene el valor de la tecla presionada

            if (ch == 'w' || ch == 'W') { // Movimiento hacia arriba
                y--;
            } else if (ch == 's' || ch == 'S') { // Movimiento hacia abajo
                y++;
            } else if (ch == 'a' || ch == 'A') { // Movimiento hacia la izquierda
                x--;
            } else if (ch == 'd' || ch == 'D') { // Movimiento hacia la derecha
                x++;
            }
        }

        // Movimiento independiente del segundo carácter (como un vector)
        x2 += vx;
        y2 += vy;

        // Si el segundo carácter llega a los bordes, cambiar su dirección
        if (x2 <= 0 || x2 >= 80) vx = -vx; // Si se llega a la izquierda o derecha, cambia la dirección
        if (y2 <= 0 || y2 >= 25) vy = -vy; // Si se llega a la parte superior o inferior, cambia la dirección

        // Mostrar los caracteres
        gotoxy(x, y);
        printf("@"); // Primer carácter (móvil con WASD)

        gotoxy(x2, y2);
        printf("*"); // Segundo carácter (móvil como vector)

        // Pausa para hacer el movimiento visible
        Sleep(100);
    }

    return 0;
}
