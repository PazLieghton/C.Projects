/*
Parcial 1 Recuperatorio
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Para hallar la longitud del string


int main() {
    int num,i;
    int salida = 0;
    
    while (!salida) {
        printf("\n\nMenu:\n");
        printf("1. \n");
        printf("2. \n");
        printf("3. \n");
        printf("4. \n");
        printf("5. Exit\n");
        printf("Ingrese Numero ");
        scanf("%d", &num);
        
        switch (num) {
            case 1:
                printf("Elegiste 1.\n");
                break;
            case 2:
                printf("\n\nElegiste 2.\n");
                break;
            case 3:
                printf("\n\nElegiste 3.\n");
                break;
            case 4:
                printf("\n\nElegiste 4.\n");
                break;
            case 5:
                printf("Saliendo...\n");
                salida = 1;
                break;
            default:
                printf("INVALIDA OPCION.\n");
                break;
        }
        
        printf("\n");
    }
    
    return 0;
}
