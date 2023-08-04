/*
Paz Sofia Lieghton Pereira
Final 2023 Primer Cuatrimestre Mayo 22

Ejercicio 1: Parta de la siguiente linea de codigo en lenguaje C.
unsigned char *r = (unsigned char *) "BOB TIENE UN RADAR QUE PUEDE RECONOCER UN
OSO EN EL BOSQUE";

El puntero r puede utilizarse como un vector de valores de tipo unsigned char.
Escriba un programa con menu repetitivo.

1. Guardar los datos en una lista doblemente enlazada y luego mostrarla en formato %bc
y binario de 8 bits. Indique cuantos bits con valor 1 y 0 hay en total en toda la lista.
Si la opcion ya fue ejecutada destruir la lista existente.

Ejemplo. B - 01000010

2. Suponga que los primeros 64 valores del vector son los registros del RTC, es decir
r [0] = registro 00, y asi sucesivamente. (Los valores pueden no tener sentido para un RTC
real). En basar a esa suposicion, muestre por pantalla los valores correspondientes al registro,
A, B y C en formato binario e indique en pantalla.

UIP Activo?
PIE y AIE Ambos Activos?
PF o AF alguno activo?*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // Librería para usleep

// Definición de la estructura Vector para la lista doblemente enlazada
typedef struct Vector {
    unsigned char datos;
    struct Vector *ant;
    struct Vector *sig;
} Vector;

// Función para crear un nuevo nodo Vector
Vector *crearVector(unsigned char datos) {
    Vector *nuevoVector = (Vector *)malloc(sizeof(Vector));  // Asigna memoria para el nuevo nodo
    nuevoVector->datos = datos;
    nuevoVector->ant = NULL;
    nuevoVector->sig = NULL;
    return nuevoVector;
}

// Función para insertar un nuevo nodo Vector al final de la lista
void FIFO(Vector **cabeza, unsigned char datos) {
    Vector *nuevoVector = crearVector(datos);
    if (*cabeza == NULL) {
        *cabeza = nuevoVector;  // Si la lista está vacía, el nuevo nodo es el primero
    } else {
        Vector *temp = *cabeza;
        while (temp->sig != NULL) {
            temp = temp->sig;  // Avanza hasta el último nodo
        }
        temp->sig = nuevoVector;  // Conecta el nuevo nodo al último
        nuevoVector->ant = temp;
    }
}

// Función para imprimir la lista en formato %bc y binario de 8 bits
void imprimir(Vector *cabeza) {
    Vector *actual = cabeza;
    int contar_0 = 0, contar_1 = 0;
    while (actual != NULL) {
        printf("%c - ", actual->datos);

        // Imprimir representación binaria de 8 bits
        unsigned char mascara = 0b10000000;
        for (int i = 0; i < 8; i++) {
            printf("%d", (actual->datos & mascara) ? 1 : 0);  // Verifica y muestra cada bit
            if ((actual->datos & mascara))
                contar_1++;  // Incrementa contador de bits 1
            else
                contar_0++;  // Incrementa contador de bits 0
            mascara >>= 1;  // Mueve la máscara de bit hacia la derecha
        }
        printf("\n");

        actual = actual->sig;
    }
    printf("Total de unos: %d\n", contar_1);  // Muestra el total de bits 1
    printf("Total de ceros: %d\n", contar_0);  // Muestra el total de bits 0
}

// Función para destruir la lista y liberar memoria
void destruirLista(Vector **cabeza) {
    Vector *actual = *cabeza;
    while (actual != NULL) {
        Vector *temp = actual;
        actual = actual->sig;
        free(temp);  // Libera memoria de cada nodo
    }
    *cabeza = NULL;
}

// Verificar si el bit UIP está activo en el carácter
int esUIPActivo(unsigned char c) {
    return (c & (1 << 7)) ? 1 : 0;  // Retorna 1 si el bit 7 está activo, 0 si no
}

// Verificar si los bits AIE y PIE están activos en el carácter
int esAIEYPIEctivo(unsigned char c) {
    int bitAIE = (c >> 6) & 1;  // Obtiene el bit AIE en posición 6
    int bitPIE = (c >> 5) & 1;  // Obtiene el bit PIE en posición 5
    return (bitAIE && bitPIE) ? 1 : 0;  // Retorna 1 si ambos bits están activos, 0 si no
}

// Verificar si los bits AF o PF están activos en el carácter
int esPFOAFctivo(unsigned char c) {
    int bitPF = (c >> 6) & 1;  // Obtiene el bit PF en posición 6
    int bitAF = (c >> 5) & 1;  // Obtiene el bit AF en posición 5
    return (bitPF || bitAF) ? 1 : 0;  // Retorna 1 si al menos uno de los bits está activo, 0 si no
}

int main() {
    Vector *cabeza = NULL;
    unsigned char *r = (unsigned char *)"BOB TIENE UN RADAR QUE PUEDE RECONOCER UN OSO EN EL BOSQUE";
    
    int opcion;
    do {
        printf("Menú:\n");
        printf("1. Guardar datos en la lista y mostrar información\n");
        printf("2. Mostrar información de registros A, B y C\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                usleep(244);  // Agregar un retraso de 244 microsegundos
                for (int i = 0; r[i] != '\0'; i++) {
                    FIFO(&cabeza, r[i]);  // Inserta cada carácter en la lista
                }
                printf("Datos guardados en la lista.\n");
                imprimir(cabeza);  // Mostrar información después de guardar los datos
                break;
            
            case 2:
                // Verificar y mostrar información de bits en caracteres específicos
                printf("Caracter: %c - Bit UIP: %s\n", r[10], esUIPActivo(r[10]) ? "Activo" : "Inactivo");
                printf("Caracter: %c - Bits AIE y PIE: %s\n", r[11], esAIEYPIEctivo(r[11]) ? "Activos" : "Inactivos");
                printf("Caracter: %c - Bits AF o PF: %s\n", r[11], esPFOAFctivo(r[12]) ? "Activo" : "Inactivo");
                break;
            
            case 3:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }

    } while (opcion != 3);

    // Liberar memoria de la lista antes de salir
    destruirLista(&cabeza);
    return 0;
}

