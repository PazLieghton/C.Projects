/*
12. Escriba un programa que permita ingresar un valor entero de 8 bits sin
signo y haga lo siguiente (empezando a contar los bits desde la derecha):
*/


#include <stdio.h>

//1
void binaryToHex(unsigned int inp) {
    printf("%X", inp);
}

//2


//3


//4


//5


//6


//7



//%hhu para unsigned char

int main() {
    int num;
    unsigned int inp;
    int salida = 0;

    
    while (!salida) {
        printf("Menu:\n");
        printf("1. Muestre el nro. ingresado en hexadecimal\n");
        printf("2. Informe si el 5to bit es cero o uno\n");
        printf("3. Informe si el primero y el cuarto bit están en uno\n");
        printf("4. Informe si el primero o el cuarto bit están en uno\n");
        printf("5. Modifique el nro. poniendo en uno los bits de los extremos\n");
        printf("6. Modifique el nro. poniendo en cero los bits de los extremos\n");
        printf("7. Niegue el nro. (ejemplo: 00110010 11001101)\n");
        printf("8. Salida\n");
        printf("Ingrese Numero ");
        scanf("%u", &inp);
        printf("\nIngrese Opcion de menu ");
        scanf("%d", &num);

        switch (num) {
            case 1:
                printf("Elegiste 1.\n");
                printf("The hexadecimal equivalent is: ");
                binaryToHex(inp);
                printf("\n");
                break;
            case 2:
                printf("Elegiste 2.\n");
                // Add code for Option 2
                break;
            case 3:
                printf("Elegiste 3.\n");
                // Add code for Option 3
                break;
            case 4:
                printf("Elegiste 4.\n");
                // Add code for Option 4
                break;
            case 5:
                printf("Elegiste 5.\n");
                // Add code for Option 5
                break;
            case 6:
                printf("Elegiste 6.\n");
                // Add code for Option 6
                break;
            case 7:
                printf("Elegiste 7.\n");
                // Add code for Option 7
                break;
            case 8:
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
