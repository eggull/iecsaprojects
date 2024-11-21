#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
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
int main(){
    char arrow, arrow_1;
        while(1){
            if(_kbhit()){

            arrow = _getch();

            

            printf("arrow =%c\t", arrow);

            printf("arrow_1 =%c\n", arrow_1);
                    /*if(arrow_1 == 'd' && arrow == 'w' && _getch() == 'd' || _getch() == 'w') //por un instante se leen las 2 letras, pero cuando esto discrepa, tiende a solo usar una funcion getch, por lo tanto, debe guardarse un valor getch simultaneamente. Leer los valores uno a uno pero esto alternando su lectura, que estará definida con una velocidad, esta velocidad tiene que ser mínima.
                    {
                        arrow = 'p'; // Diag to norest
                    }
            printf("%c\n", arrow);*/
            }
        }
        system("pause");
    }