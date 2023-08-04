/*
PARCIAL 2. PAZ SOFIA LIEGHTON PEREIRA PROGRAMACION 24 de JUNIO 2023
*/

/*
RESPUESTAS DE LA TEORIA

Suponga que tiene que ejecutar un programa de 6 instrucciones. Cada instrucción 
requiere 4 ciclos de clock para completarse (Fetch, decode, execution, write-back)
Si tiene un procesador con velocidad 100MHz. Cuánto tarda en ejecutarse?

Imaginemos a una CPU con 4 clocks del estilo de arquitectura von Neumann

Cada instrucción debe generar cuatro "Vueltas" de círculo, a una velocidad de
100Mhz, sumando un total de 400MHz por instrucción.

A su vez, el programa a ejecutar tiene 6 instrucciones, multiplicando nuestro
tiempo de ejecución x instrucción 6 veces, obtenemos 2400MHz, equivalente a 
2.4GHz, un número similar al clock normal de una CPU Intel Core i3, aunque este último
tiene un clock de 2.4GHz POR INSTRUCCIÓN, nuestra CPU tiene de 400MHz, equivalente a una PC
noventera.

Como las Compaq con Windows 98 :D una Ferrari

El tiempo es T = 1/f

Entonces 1 Mhz es 1 microsegundo

2400 MegaHertz son 2400 microsegundos, equivalente a 2.4 milisegundos

Este es el tiempo que tarda el procesador en ejecutar todo.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para hallar la longitud del string

#define P 0x70 /* RTC */
#define N 256

// Función para convertir valor binario a BCD
unsigned char binaryToBCD(unsigned char binaryValue) {
    unsigned char tens = binaryValue / 10;
    unsigned char ones = binaryValue % 10;
    unsigned char bcdValue = (tens << 4) | ones;
    return bcdValue;
}

// FUNCIONES PARA EL ITEM 1 //

// Imprime el valor en formato binario
void printBinary(unsigned char value) {
    for (int i = 7; i >= 0; i--) {
        unsigned char mask = 1 << i;
        unsigned char bit = (value & mask) ? 1 : 0;
        printf("%d", bit);
    }
}

// Imprime el valor en formato hexadecimal
void decimalToHex(unsigned char decimal) {
    printf("El valor en hexadecimal es: 0x%02X ", decimal);
}

// FUNCIONES PARA EL ITEM 2

// Genero una estructura para guardar los bits en un datos.bin //
struct lista {
    unsigned char bits[8];
} s; // Hago Typedef s //

// Función para publicar valor binario (¿necesaria?)
unsigned char publishBinary(unsigned char value) {
    int bit;
    for (int i = 7; i >= 0; i--) {
        unsigned char mask = 1 << i;
        unsigned char bit = (value & mask) ? 1 : 0;
    }
    return bit;
}

// FUNCIONES PARA EL ITEM 3

// Imprime el valor de los minutos en formato hexadecimal
void decimalToHexMinutos(unsigned char decimal) {
    printf("El valor de los minutos es: %02X ", decimal);
}

// Imprime el valor de los minutos de alarma en formato hexadecimal
void decimalToHexMinutosalarma(unsigned char decimal) {
    printf("El valor de los minutos de alarma es: %02X ", decimal);
}

// Función para verificar si un número es BCD válido
int esBCD(unsigned char num) {
    if ((num & 0xF0) <= 0x90 && (num & 0x0F) <= 0x09) {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    /* Se parte de estas dos líneas de código */
    char *datos = "QUIERO ganar la tercera."; // Mayúsculas y minúsculas necesarias
    unsigned char *r = (unsigned char *)datos;
    // Usar vector de puntero r //

    // USO LA LONGITUD DEL STRING
    int a;
    a = strlen(datos);
    printf("Longitud de string: %d\n", a);

    int num, i;
    int salida = 0;

    printf("EN PRIMERA INSTANCIA ESTOS SON LOS VALORES DEL VECTOR EN INT\n");
    for (i = 0; i < a; i++) {
        printf("%hhu ", r[i]);
    }

    while (!salida) {
        printf("\n\nMenu:\n");
        printf("1. Convertir vector a binario, hexadecimal y si es válido BCD.(COMPLETA)(Falta solo BCD)\n");
        printf("2. Guardar los datos del vector en datos.bin aquellos que tienen los bits menos significativos en 11.(Pude hallar los valores que quería, no pude escribir)\n");
        printf("3. Informar minutos de la hora de la hora actual del vector y la alarma programada (COMPLETA)\n");
        printf("4. PERIODIC FLAG ACTIVO? (COMPLETO) \n");
        printf("5. Exit (COMPLETA)\n");
        printf("Ingrese Numero ");
        scanf("%d", &num);

        switch (num) {
            case 1:
                printf("Elegiste 1.\n");
                printf("\n\nCONVERSIÓN A BINARIA: \n");
                for (i = 0; i < a; i++) {
                    printBinary(r[i]);
                    printf("= %hhu  \n", r[i]);
                    if (esBCD(r[i])) {
                        printf("Es un BCD válido.\n");
                    } else {
                        printf("No es un BCD válido.\n");
                    }
                }
                unsigned char bcdValue = binaryToBCD(r[i]);
                printf("Valor en BCD: %02X\n", bcdValue);
                printf("\n|||||||||||||||||||||||||||||");
                printf("\n\nCONVERSIÓN A HEXAGESIMAL: \n");
                for (i = 0; i < a; i++) {
                    decimalToHex(r[i]);
                    printf("= %hhu  \n", r[i]);
                    if (esBCD(r[i])) {
                        printf("Es un BCD válido.\n");
                    } else {
                        printf("No es un BCD válido.\n");
                    }
                }
                break;
            case 2:
                printf("\n\nElegiste 2. Estos son los punteros válidos\n");

                FILE *outfile;

                outfile = fopen("datos.bin", "wb"); // Abrir el archivo en modo binario

                if (outfile == NULL) {
                    fprintf(stderr, "\nError al abrir el archivo\n");
                    exit(1);
                }

                for (i = 0; i < a; i++) {
                    if ((r[i] & 0x03) == 0x03) { // Verificar si los bits menos significativos son 11
                        printf("Guardando: ");
                        printBinary(r[i]);
                        printf("= %hhu\n", r[i]);
                        fwrite(&r[i], sizeof(unsigned char), 1, outfile);
                    }
                }

                fclose(outfile); // Cerrar el archivo
                printf("\nDatos guardados en archivo datos.bin");
                break;

            case 3:
                printf("\n\nElegiste 3.\n");
                decimalToHexMinutos(r[2]);
                printf("\n");
                decimalToHexMinutosalarma(r[3]);
                break;
            case 4:
                printf("\n\nElegiste 4.\n");
                if ((r[13] & 0x40) != 0) /* 0x40 = 0000 1000, si es != 0 está activo */
                    printf("\nPeriodic Flag Activo\n");
                else
                    printf("\nPeriodic Flag no Activo\n");
                break;
            case 5:
                printf("Saliendo...\n");
                salida = 1;
                break;
            default:
                printf("OPCIÓN INVÁLIDA.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}