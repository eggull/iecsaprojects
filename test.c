/* 
Con este código nos podemos apoyar para el movimiento del personaje
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // Para usar _kbhit() y _getch()

#define ALTURA 10
#define ANCHO 10

void limpiarPantalla() {
    // Limpia la pantalla para que el movimiento sea visible
    system("cls");  // "cls" en Windows, "clear" en Linux/macOS
}

void dibujarMapa(int x, int y) {
    // Imprimir el mapa con el personaje en su posición actual
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < ANCHO; j++) {
            if (i == y && j == x) {
                printf("*");  // El personaje
            } else {
                printf(".");  // Espacio vacío
            }
        }
        printf("\n");
    }
}

int main() {
    int x = 5, y = 5;  // Posición inicial del personaje
    char tecla;

    while (1) {
        limpiarPantalla();
        dibujarMapa(x, y);

        if (_kbhit()) {  // Verificar si se ha presionado una tecla
            tecla = _getch();  // Capturar la tecla presionada

            // Mover el personaje con las teclas WASD
            switch (tecla) {
                case 'w':  // Arriba
                    if (y > 0) y--;
                    break;
                case 's':  // Abajo
                    if (y < ALTURA - 1) y++;
                    break;
                case 'a':  // Izquierda
                    if (x > 0) x--;
                    break;
                case 'd':  // Derecha
                    if (x < ANCHO - 1) x++;
                    break;
                case 'q':  // Salir con 'q'
                    return 0;
                default:
                    break;
            }
        }

        // Pausar para hacer el movimiento visible (opcional)
        // usleep(100000);  // Descomentar si se quiere hacer una pausa entre actualizaciones
    }

    return 0;
}
