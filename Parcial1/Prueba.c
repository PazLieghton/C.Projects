#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

struct rtc
{
    unsigned char segundos;
    unsigned char segundos_alarma;
    unsigned char minutos;
    unsigned char minutos_alarma;
    unsigned char horas;
    unsigned char horas_alarma;
    unsigned char dia_semama;
    unsigned char dia_mes;
    unsigned char mes;
    unsigned char ano2;
    unsigned char regA;
    unsigned char regB;
    unsigned char regC;
    unsigned char regD;
    unsigned long long int relleno1;
    unsigned long long int relleno2;
    unsigned long long int relleno3;
    unsigned long long int relleno4;
    unsigned long long int relleno5;
    unsigned long long int relleno6;
    unsigned long long int relleno7;
    unsigned long long int relleno8;
    unsigned char relleno9;
    unsigned char relleno10;
};


/*RESPUESTA TEORICA - Paz Sofia Lieghton Pereira

a) Cual es la diferencia entre microprocesador y microcontrolador
Un microcontrolador tiene la gran ventaja de ser una computadora miniaturizada y por lo tanto tiene todo lo necesario, CPU, memoria, registros, para realizar una tarea especifica, por ejemplo, usado en su mayoria en sistemas enbebidos.

EL microprocesador es simplemente un elemento CPU/GPU integrado en un paquete, de por si, no puede realizar tareas de sistemas embebidos.

Un ejemplo (Trabajo con esto)
Los microcontroladores de raspberry pi mini sirve para todo tipo de tareas simples, a su vez, dentro de el existe microprocesador RP2040 que esta dentro del pi mini, con acceso a io y arimetica (Como toda cpu).

b) Las 3 etapas del pipeline de cortex m3 y sus ventajas

Fetch(Buscar) - Decodificar - Ejecutar, la ejecucion es muy deterministica y de bajo consumo, perfecto para tareas simples como controlar una tostadora o bloquear avisos publicitarios en la red de internet.
/*




/*void Hexabin(char* hex)
{

    int i = 0;

    while (hex[i]) {
        switch (hex[i]) {
        case '0':
            printf("0000");
            break;
        case '1':
            printf("0001");
            break;
        case '2':
            printf("0010");
            break;
        case '3':
            printf("0011");
            break;
        case '4':
            printf("0100");
            break;
        case '5':
            printf("0101");
            break;
        case '6':
            printf("0110");
            break;
        case '7':
            printf("0111");
            break;
        case '8':
            printf("1000");
            break;
        case '9':
            printf("1001");
            break;
        case 'A':
        case 'a':
            printf("1010");
            break;
        case 'B':
        case 'b':
            printf("1011");
            break;
        case 'C':
        case 'c':
            printf("1100");
            break;
        case 'D':
        case 'd':
            printf("1101");
            break;
        case 'E':
        case 'e':
            printf("1110");
            break;
        case 'F':
        case 'f':
            printf("1111");
            break;
        }
        i++;
    }
}
*/


int main()
{
    struct rtc v[23];
    FILE *arch;
    int n = 1, i = 0, op, tam;

    arch = fopen("valores.bin", "rb");
    if(arch == NULL)
    {
        printf("Error en lectura de archivio\n");
        exit(1);
    }
    while(n == 1)
    {
        n = fread(&v[i], sizeof(struct rtc), 1, arch);
        i++;
    }

    if(fclose(arch) != 0)
    {
        printf("Error al cerrar archivo\n");
        exit(1);
    }

    printf("OPCIONES\n");
    printf("1-Size del archivo\n");
    printf("2-IMPRIMIR PRIMEROS 14 VALORES DE RTC EN HEXA(BIEN)\n");
    printf("3-IMPRIMIR PRIMEROS 14 VALORES DE RTC EN BINARIO\n");
    printf("4-Mostrar hora en formato estandar\n");
    printf("5-AIE(BIEN)\n");
    printf("6-Salir\n");
    scanf("%d", &op);

    while(op != 6)
    {
        switch(op)
        {
            case 1: tam = (i+2)*64;
                    printf("El tamanio del archivo es de %d bytes\n", tam);
                    break;
            case 2:
                    printf("Hora: %02x:%02x:%02x\n", v[7].horas, v[7].minutos, v[7].segundos);
                    printf("Hora Alarma: %02x:%02x:%02x\n", v[7].horas_alarma, v[7].minutos_alarma, v[7].segundos_alarma);
                    printf("Year: 20%02x\n", v[7].ano2);
                    printf("Dia Semana: %02x\n", v[7].dia_semama);
                    printf("Dia Mes: %02x\n", v[7].dia_mes);
                    printf("Mes: %02x\n", v[7].mes);
                    printf("regA: %02x\n", v[7].regA);
                    printf("regB: %02x\n", v[7].regB);
                    printf("regC: %02x\n", v[7].regC);
                    printf("regD: %02x\n", v[7].regD);
                    break;
            case 3: printf("Hora: %02x:%02x:%02x\n",v[7].horas, v[7].minutos, v[7].segundos);
                    printf("Hora Alarma: %02x:%02x:%02x\n", v[7].horas_alarma, v[7].minutos_alarma, v[7].segundos_alarma);
                    printf("Year: 20%02x\n", v[7].ano2);
                    printf("Dia Semana: %02x\n", v[7].dia_semama);
                    printf("Dia Mes: %02x\n", v[7].dia_mes);
                    printf("Mes: %02x\n", v[7].mes);
                    break;
            case 4: printf("Hora: %02x:%02x:%02x de 20%02x\n",  v[7].horas, v[7].minutos, v[7].segundos,v[7].ano2);
                    break;
            case 5: if((v[7].regB & 0x20) != 0) printf("El bit AIE esta en 1.HAY ALARMA PROGRAMADA\n");
                    else printf("\nEl bit AIE esta en 0 NO HAY ALARMA PROGRAMADA\n");
                    break;
            default:    printf("Por favor, elija una opcion valida\n");
                        break;
        }
        printf("OPCIONES\n");
        printf("1-Size del archivo\n");
        printf("2-IMPRIMIR PRIMEROS 14 VALORES DE RTC EN HEXA\n");
        printf("3-IMPRIMIR PRIMEROS 14 VALORES DE RTC EN BINARIO\n");
        printf("4-Mostrar hora en formato estandar\n");
        printf("5-AIE alarma programada\n");
        printf("6-Salir\n");
        scanf("%d", &op);
    }
    return 0;
}
