#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <pthread.h>
#include <conio.h>

#define WIDTH 150
#define HEIGHT 40

// Estructura para representar las coordenadas del cursor
typedef struct {
    int x;
    int y;
} Position;

// Cola para almacenar las posiciones
Position taskQueue[100];  // Cola con capacidad de 100 tareas
int queueStart = 0;  // Inicio de la cola
int queueEnd = 0;    // Fin de la cola
pthread_mutex_t queueMutex;  // Mutex para asegurar acceso exclusivo a la cola
pthread_cond_t taskReadyCond; // Condición para saber cuando hay tareas

// gotoxy para mover el cursor
void gotoxy(int x, int y) {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

// Función para agregar tareas a la cola
void addTaskToQueue(int x, int y) {
    pthread_mutex_lock(&queueMutex);  // Bloquear acceso a la cola

    taskQueue[queueEnd].x = x;
    taskQueue[queueEnd].y = y;
    queueEnd = (queueEnd + 1) % 100;  // Asegurarse de que la cola no se desborde

    pthread_cond_signal(&taskReadyCond);  // Notificar que hay tareas pendientes

    pthread_mutex_unlock(&queueMutex);  // Liberar acceso a la cola
}

// Función que simula el movimiento de los asteroides
void *asteroid(void *arg) {
    int x = WIDTH;
    int y = rand() % HEIGHT;  // Y aleatorio para cada asteroide
    while (x > 0) {
        addTaskToQueue(x, y);  // Agregar tarea a la cola
        x--;  // Mover asteroide hacia la izquierda
        Sleep(50);  // Esperar un poco
    }
    return NULL;
}

// Función que mueve el jugador
void *playerMovement(void *arg) {
    int x = 10, y = 10;
    while (1) {
        if (_kbhit()) {
            char ch = _getch();
            switch (ch) {
                case 'w': y--; break;
                case 's': y++; break;
                case 'a': x--; break;
                case 'd': x++; break;
            }
            addTaskToQueue(x, y);  // Agregar tarea a la cola
        }
        Sleep(100);  // Esperar un poco
    }
    return NULL;
}

// Función del hilo coordinador para mover el cursor
void *cursorCoordinator(void *arg) {
    while (1) {
        pthread_mutex_lock(&queueMutex);  // Bloquear el acceso a la cola

        while (queueStart == queueEnd) {
            pthread_cond_wait(&taskReadyCond, &queueMutex);  // Esperar a que haya tareas
        }

        // Tomar la siguiente tarea de la cola
        Position pos = taskQueue[queueStart];
        queueStart = (queueStart + 1) % 100;

        pthread_mutex_unlock(&queueMutex);  // Liberar el acceso a la cola

        gotoxy(pos.x, pos.y);  // Mover el cursor a la posición
        printf("*");  // Imprimir el asteroide o jugador
    }
    return NULL;
}

int main() {
    // Inicializar mutex y condición
    pthread_mutex_init(&queueMutex, NULL);
    pthread_cond_init(&taskReadyCond, NULL);

    // Crear los hilos
    pthread_t asteroidThread1, asteroidThread2, playerThread, coordinatorThread;
    pthread_create(&asteroidThread1, NULL, asteroid, NULL);
    pthread_create(&asteroidThread2, NULL, asteroid, NULL);
    pthread_create(&playerThread, NULL, playerMovement, NULL);
    pthread_create(&coordinatorThread, NULL, cursorCoordinator, NULL);

    // Esperar que los hilos terminen (en este caso los hilos de asteroides y jugador son infinitos)
    pthread_join(asteroidThread1, NULL);
    pthread_join(asteroidThread2, NULL);
    pthread_join(playerThread, NULL);
    pthread_join(coordinatorThread, NULL);

    // Limpiar recursos
    pthread_mutex_destroy(&queueMutex);
    pthread_cond_destroy(&taskReadyCond);

    return 0;
}
