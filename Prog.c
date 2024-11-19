/*
UNIVERSIDAD AERONAUTICA DE QUERETARO
PAUL BRIAN TELLEZ RICO 
MATRICULA: 12147
PROGRAMACION I
TAREA - Menú
01/11/2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int fibonacci(int e){
    int v1, v2, cont;
        int f[e];
        v1=0;
        v2=1;
        cont=0;
            while(cont<e){
                f[cont]=v1;
                printf("Elemento %d\n", f[cont]);
                cont++; 
                    if(cont==e){break;}
                        f[cont]=v2;
                        printf("Elemento %d\n", f[cont]);
                        cont++;
                        v1=v1+v2;
                        v2=v2+v1;}
                        system("pause");
                        return f[e];}
void multiplicacion(int numero){
int r,c,q,i,j,a,b,v,s;
printf("Renglones de la 1era Matriz\n");
scanf("%d", &r);
printf("Columnas de la 1era Matriz\n");
scanf("%d", &c);
int mat[r][c];
printf("Columna de la 2da Matriz\n");
scanf("%d", &q);
int m[c][q];
int u[r][q];
       for( i=0; i<r; i++){
        for( j=0; j<c; j++){
            printf("valor de matriz 1 en posicion> %d,%d=", i, j);
            scanf("%d", &mat[i][j]);}
            }
        for( i=0; i<c; i++){
         for( j=0; j<q; j++){
            printf("valor de matriz 2 en posicion> %d,%d=", i, j);
            scanf("%d", &m[i][j]);
            }
            }
            for(i=0; i<r; i++){
                for(j=0; j<q; j++){s=0;
                    for(v=0; v<c; v++){
                        s=s+((mat[i][v])*(m[v][j]));
            }u[i][j]=s;}}
            for( b=0; b<r; b++){
        for( a=0; a<q; a++){
            printf("%d\t", u[b][a]);
            }
            printf("\n");
            }
            system("pause");
            return;}
void suma(int numero){
int r,c,i,j,a,b,v,ban=1,s,ban2;
printf("Renglones de la matriz\n");
scanf("%d", &r);
printf("Columnas de la matriz\n");
scanf("%d", &c);
int mat[r][c];
int m[r][c];
int u[r][c];
   MATRIZ: for( i=0; i<r; i++){
        for( j=0; j<c; j++){
            if(ban==1){
            printf("Valor de matriz 1 en %d,%d=", i, j);
            scanf("%d", &mat[i][j]);}
                else{
                printf("Valor de matriz 2 en %d,%d=", i, j);
                scanf("%d", &m[i][j]);
                u[i][j]=(mat[i][j])+(m[i][j]);
                ban2=1;
                }
                }
                }
                ban=0;
                    if(ban==0 && ban2==1){goto sigue;}
                        i=0;
                        j=0;
                    goto MATRIZ;
                        sigue:
                        for( b=0; b<r; b++){
                        for( a=0; a<c; a++){
                        printf("%d\t", u[b][a]);
                        }
                        printf("\n");
                        }
                        system("pause");
                        return;}
void bubblesort(int numero){
    int i, r, o, t, z, j;
    int a[50];
    o=1;
    r=0;
    t=0;
    z=0;
    srand(time(0));
    printf("Arreglo principal\n");
    for(i=0; i<50; i++){
        a[i]=(rand() % 51);
       printf("%d,", (a[i]));
        }
        printf("\n");
        printf("\n");
        printf("Arreglo con bubblesort\n");
        do{
            for(j=0; j<50; j++){
                if((a[j])>(a[j+1]) && (a[j])!=(a[j+1])){
                    
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;}
                    }
                    r++;
                    }
                    while(r<50 && o==1);
                    while(z<50){
                    printf("%d,", (a[z+1]));
                    z++;
                    }
                    system("pause");
                    return;}
void impares (int numero){
 int a[20];
        for(int i=0; i<20; i++){
            a[i]=i*2+1;
            printf("Elemento %d = %d\n", i, a[i]);
            }
            system("pause");
            return;}
int main(){
    int numero, e;
    printf("Menú de funciones con matrices , arreglos, fibonacci, etc...\n\n");
    printf("Escribe 1 para multiplicacion de matrices\n");
    printf("Escribe 2 para suma de matrices \n");
    printf("Escribe 3 para serie de fibonacci\n");
    printf("Escribe 4 para impares con arreglo\n");
    printf("Escribe 5 para bubblesort\n");
    scanf("%d", &numero);
    printf("\n");
    switch(numero){
        case 1:
            multiplicacion(numero);break;
        case 2:
            suma(numero);break;
        case 3:
            printf("Elemento en serie fibonacci:");
            scanf("%d", &e);
            fibonacci(e);break;
        case 4:
            impares(numero);break;
        case 5:
            bubblesort(numero);break;
        default: printf("Error, ingresa valores correctos.");
        return 0;}}