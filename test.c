#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>
#include <conio.h>  // Para usar _kbhit() y _getch()

// Definimos una estructura para almacenar las coordenadas
typedef struct {
    int x;
    int y;
} Position;

// Función gotoxy utilizando la API de Windows
void gotoxy(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { x, y };
    SetConsoleCursorPosition(hConsole, coord);
}

// Función para imprimir un objeto en la pantalla en una posición dada
void print_at(Position pos, const char *text) {
    gotoxy(pos.x, pos.y);
    printf("%s", text);
}

// Definimos las posiciones de diferentes objetos
Position player_pos = {10, 10};    // Posición del jugador
Position asteroid_pos = {30, 5};   // Posición de un asteroide
Position score_pos = {50, 1};      // Posición para mostrar la puntuación

// Función del jugador, mueve el jugador en la pantalla
void *move_player(void *arg) {
    int i = 0;
    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            switch (ch) {
                case 'w': // Mover arriba
                    player_pos.y--;
                    break;
                case 's': // Mover abajo
                    player_pos.y++;
                    break;
                case 'a': // Mover izquierda
                    player_pos.x--;
                    break;
                case 'd': // Mover derecha
                    player_pos.x++;
                    break;
            }
            print_at(player_pos, "Player");  // Actualizamos la posición del jugador
            Sleep(50);  // Pausa para evitar movimientos muy rápidos
        }
    }
    return NULL;
}

// Función para mostrar el asteroide
void *move_asteroid(void *arg) {
    int i = 0;
    while (1) {
        print_at(asteroid_pos, "Asteroid");
        Sleep(50);  // Pausa para simular movimiento del asteroide
        asteroid_pos.y++;  // Mover el asteroide hacia abajo
        if (asteroid_pos.y > 20) {
            asteroid_pos.y = 1; // Reiniciar la posición si el asteroide se salió de la pantalla
        }
    }
    return NULL;
}

// Función para mostrar el puntaje
void *show_score(void *arg) {
    int score = 0;
    while (1) {
        print_at(score_pos, "Score: ");
        printf("%d", score);
        score++;
        Sleep(1000);  // Actualizar el puntaje cada segundo
    }
    return NULL;
}

int main() {
    pthread_t player_thread, asteroid_thread, score_thread;

    // Inicializamos las posiciones de los objetos
    print_at(player_pos, "Player");
    print_at(asteroid_pos, "Asteroid");
    print_at(score_pos, "Score: 0");

    // Creamos los hilos para cada función
    pthread_create(&player_thread, NULL, move_player, NULL);
    pthread_create(&asteroid_thread, NULL, move_asteroid, NULL);
    pthread_create(&score_thread, NULL, show_score, NULL);

    // Esperamos a que los hilos terminen
    pthread_join(player_thread, NULL);
    pthread_join(asteroid_thread, NULL);
    pthread_join(score_thread, NULL);

    return 0;
}
