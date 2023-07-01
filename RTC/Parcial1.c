/*
El archivo rtc.bin es un archivo binario de tamaño desconocido pero menor a 256 bytes.
Los primeros 64 bytes del archivo corresponden a los registros/memoria del RTC de una PC.
Se pide escribir un programa en C que lea el archivo y muestre un menú repetitivo que en base a su contenido permita las
siguientes opciones

1) Informar el tamaño del archivo
2) Mostrar la hora en formato hh:mi:ss
3) Mostrar el año completo en formato aaaa, es decir, si fuera 2022 debería mostrar "2022"
4) Informar si el bit AIE está activo (si/no)
5) Salir
*/

#include <stdio.h>
#include <stdlib.h>
/*
Los 64 bytes son de 0x00 a 0x3F, 0-63 => si c/u ocupa 1 byte, con unsigned char deberia leerlos bien
Puedo generar un vector de tipo unsigned char de 256 posiciones
 */
#define N 256

int main()
{
    FILE* f;
    unsigned char v[N];
    int aux, n, op;

    f = fopen("rtc.bin", "rb");
    if (f == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    n = fread(v, sizeof(unsigned char), N, f);

    aux = fclose(f);
    if (aux != 0) {
        printf("Error al cerrar el archivo.\n");
        return 2;
    }

    do {
        printf("\n---------Menu-----------");
        printf("\n1) informar el tamaño del archivo\n");
        printf("2) Mostrar la hora en formato hh:mi:ss\n");
        printf("3) Mostrar el año completo\n");
        printf("4) Informar si el bit AIE está activo (si/no)\n");
        printf("5) Salir \n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("\nEl archivo ocupa %d bytes\n\n", n);
                break;
            case 2:
                printf("\n%02x:%02x:%02x\n", v[4], v[2], v[0]);
                break;
            case 3:
                printf("\nAnio: %02x%02x\n\n", v[0x32], v[9]); /* El 32 hexa = 50 decimal */
                break;
            case 4:
                if ((v[11] & 0x20) != 0) /* 0x20 = 0010 0000, si es != 0 está activo */
                    printf("\nAIE Activo\n");
                else
                    printf("\nAIE NO Activo\n");
                break;
            default:
                break;
        }
    } while (op != 5);

    return 0;
}