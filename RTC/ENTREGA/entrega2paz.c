/*
PARCIAL 2. PAZ SOFIA LIEGHTON PEREIRA PROGRAMACION 24 de JUNIO 2023
*/

/*
RESPUESTAS DE LA TEORIA

Suponga que tiene que ejecutar un programa de 6 instrucciones. Cada instruccion 
requiere 4 ciclos de clock para completarse (Fetch, decode, execution, write-back)
Si tiene un procesador con velocidad 100MHz. Cuanto tarda en ejecutarse?

Imaginemos a una CPU con 4 clocks del estilo de arquitectura von Neumann

Cada instruccion debe generar cuatro "Vueltas" de circulo, a una velocidad de
100Mhz, sumando un total de 400MHz por instruccion.

A su vez, el programa a ejecutar tiene 6 instrucciones, multiplicando nuestro
tiempo de ejecucion x instruccion 6 veces, obtenemos 2400MHz, equivalente a 
2.4GHz, un numero similar al clock normal de una cpu intel core I3, aunque este ultimo
tiene un clock de 2.4GHz POR INSTRUCCION, nuestra cpu tiene de 400MHz, equivalente a una Pc
noventera.

Como las compaqs! con windows 98 :D una ferrari

el tiempo es T = 1/f

Entonces 1 Mhz es 1 micro segundo

2400 MegaHertz son 2400 micro segundos, equivalente a 2.4 milisegundos

Este es el tiempo que tarda el procesador en ejecutar todo.


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Para hallar la longitud del string

#define P 0x70 /*RTC*/ 
#define N 256

//FUNCIONES PARA EL ITEM 1//

void printBinary(unsigned char value) {
    for (int i = 7; i >= 0; i--) {
        unsigned char mask = 1 << i;
        unsigned char bit = (value & mask) ? 1 : 0;
        printf("%d", bit);
    }
}

void decimalToHex(unsigned char decimal) {
    printf("El valor en hexadecimal es: 0x%02X ", decimal);
}


//FUNCIONES PARA EL ITEM 2

//Genero una lista para guardar los bits en un datos.bin//

struct lista
{
    unsigned char bits[8];
}s;//Hago Typedef s//


unsigned char publishBinary(unsigned char value) {
    int bit;
    for (int i = 7; i >= 0; i--) {
        unsigned char mask = 1 << i;
        unsigned char bit = (value & mask) ? 1 : 0;
    }
    return bit;
}
//FUNCIONES PARA EL ITEM 3


void decimalToHexMinutos(unsigned char decimal) {
    printf("El valor de los minutos es: %02X ", decimal);
}

void decimalToHexMinutosalarma(unsigned char decimal) {
    printf("El valor de los minutos de alarma es: %02X ", decimal);
}


int main() {

    /*Se parte de estas dos lineas de codigo*/
    char * datos = "QUIERO ganar la tercera."; //Mayus y minimos necesarios
    unsigned char *r = (unsigned char*) datos;
    //Usar vector de puntero r//

    //USO LA LONGITUD DEL STRING
    int a;
    a = strlen(datos);
    printf("Longitud de string: %d\n",a);

    int num,i;
    int salida = 0;

    printf("EN PRIMERA INSTANCIA ESTOS SON LOS VALORES DEL VECTOR EN INT\n");
    for (i = 0 ; i < a ; i++){
        printf("%hhu ", r[i]);
    }
    
    while (!salida) {
        printf("\n\nMenu:\n");
        printf("1. Convertir vector a binario, hexadecimal y si es valido BCD.(COMPLETA)(Falta solo BCD)\n");
        printf("2. Guardar los datos del vector en datos.bin aquellos que tienen los bits menos significativos en 11.(Pude hallar los valores que queria, no pude escribir)\n");
        printf("3. Informar minutos de la hora de la hora actual del vector y la alarma programada (COMPLETA)\n");
        printf("4. PERIODIC FLAG ACTIVO? (COMPLETO) \n");
        printf("5. Exit (COMPLETA)\n");
        printf("Ingrese Numero ");
        scanf("%d", &num);
        
        switch (num) {
            case 1:
                printf("Elegiste 1.\n");
                printf("\n\nCONVERSION A BINARIA: \n");
                for (i = 0 ; i<a ; i++){
                    printBinary(r[i]);
                    printf("= %hhu  \n",r[i]);
                }
                printf("\n|||||||||||||||||||||||||||||");
                printf("\n\nCONVERSION A HEXAGESIMAL: \n");
                for (i = 0 ; i<a ; i++){
                    decimalToHex(r[i]);
                    printf("= %hhu  \n",r[i]);
                }     
                printf("\n|||||||||||||||||||||||||||||");
                printf("\n\n Es valido BCD?");
                printf("\n Para que sea valido BCD hay que partir cada numero componente del vector y convertirlo");
                printf("\n EL SEGMENTO BCD NO ESTA LISTO TODAVIA");
                break;
            case 2:
                printf("\n\nElegiste 2. Estos son los punteros validos\n");
                //TEST LOGICO
                for (i = 0 ; i<a ; i++){
                    if ((r[i] & 0x02) !=0) {
                        if ((r[i] & 0x01)!=0) {
                            printBinary(r[i]);
                            printf("= %hhu\n",r[i]);

                        }
                    }
                }     
                printf("\n Guardando en archivo datos.bin");
                break;
                /*Segmento archivo*/
                //NO FUNCIONO MI TEXTO PERO DEJO EL CROQUIS//
                /*
                FILE *outfile;

                outfile = fopen("datos.bin", "w");

                if (outfile == NULL)
                {
                    fprintf(stderr, "\nOPENERROR\n");
                    exit (1);
                }

                for (i = 0 ; i<a ; i++){
                    if ((r[i] & 0x02) !=0) {
                        if ((r[i] & 0x01)!=0) {
                            s.bits = (printBinary(r[i]));
                        }
                    }
                }     
                if(fwrite != 0)
                    printf("LISTO!\n");
                else
                    printf("WERROR\n");
                 fclose (outfile);


                */

            case 3:
                printf("\n\nElegiste 3.\n");
                decimalToHexMinutos(r[2]);
                printf("\n");
                decimalToHexMinutosalarma(r[3]);
                break;
            case 4:
                printf("\n\nElegiste 4.\n");
                if ((r[13] & 0x20) != 0) /*0x20 = 0010 0000, si es != 0 está activo*/
                    printf("\nPeriodic FLag Activo\n");
                else
                    printf("\nPeriodic Flag no Activo\n");
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
