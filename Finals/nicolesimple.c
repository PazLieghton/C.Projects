#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Nodo {
    char dato;
    struct Nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* primero;
    Nodo* ultimo;
} ListaSimple;

void borrar(ListaSimple*);
void imprimirLista(ListaSimple*);
ListaSimple insertarFinal(ListaSimple, char);
void imprimirABC(ListaSimple*);
void revisarRegistros(ListaSimple*);
void binario(char);

int main() {
    char *datos = "BOB TIENE UN RADAR QUE PUEDE RECONOCER UN OSO EN EL BOSQUE";
    unsigned char *r = (unsigned char*) datos;

    ListaSimple caracteres;
    caracteres.primero = NULL;
    caracteres.ultimo = NULL;

    int i = 0;
    int choice;

    do {
        printf("\nMENU:\n");
        printf("1. Guardar en lista y luego imprimir en %%c y binario de 8 bits\n");
        printf("2. Imprimir A, B y C en binario e indique el estado de: UIP, (PIE & AIE), (PF ó AF)\n");
        printf("3. Salir\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            borrar(&caracteres);
            caracteres.primero = NULL;
            caracteres.ultimo = NULL;

            i = 0;

            while (r[i] != 0) {
                caracteres = insertarFinal(caracteres, r[i]);
                i++;
            }

            imprimirLista(&caracteres);
            break;

        case 2:
            if (caracteres.primero != NULL) {
                imprimirABC(&caracteres);
                revisarRegistros(&caracteres);
            }
            break;

        default:
            break;
        }

    } while (choice != 3);

    borrar(&caracteres);
    return 0;
}

void borrar(ListaSimple* lista) {
    Nodo* actual = lista->primero;
    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    lista->primero = NULL;
    lista->ultimo = NULL;
    printf("\nLista existente borrada exitosamente.\n");
}

void binario(char a) {
    int k = 1, auxiliar = 0, bin = 0;
    while (a != 0) {
        auxiliar = a % 2;
        a /= 2;
        bin += auxiliar * k;
        k *= 10;
    }
    printf("%d\n", bin);
}

void imprimirLista(ListaSimple* lista) {
    int i = 0;
    Nodo* actual = lista->primero;
    printf("\nDato   Caracter   Hexadecimal   Binario\n");
    while (actual != NULL) {
        printf("%d\t%c\t0x%x\t", i, actual->dato, actual->dato);
        binario(actual->dato);
        i++;
        actual = actual->siguiente;
    }
}

ListaSimple insertarFinal(ListaSimple lista, char dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    if (lista.primero == NULL) {
        lista.primero = nuevoNodo;
        lista.ultimo = nuevoNodo;
    } else {
        lista.ultimo->siguiente = nuevoNodo;
        lista.ultimo = nuevoNodo;
    }

    return lista;
}

void imprimirABC(ListaSimple* lista) {
    int i = 0;
    Nodo* actual = lista->primero;
    printf("\nDato   Caracter   Hexadecimal   Binario\n");
    while (actual != NULL) {
        if (i == 10 || i == 11 || i == 12) {
            printf("%d\t%c\t0x%x\t", i, actual->dato, actual->dato);
            binario(actual->dato);
        }
        i++;
        actual = actual->siguiente;
    }
}

void revisarRegistros(ListaSimple* lista) {
    int i = 0;
    Nodo* actual = lista->primero;
    printf("\nRevisando el estado de los bits UIP, PIE, AIE, PF y AF:\n");

    while (actual != NULL) {
        if (i == 10) {
            if ((actual->dato & 0x80) != 0) {
                printf("UIP activo\n");
            } else {
                printf("UIP inactivo\n");
            }
        }

        if (i == 11) {
            if ((actual->dato & 0x60) == 0x60) {
                printf("El grupo PIE y AIE se encuentran ambos activos\n");
            } else {
                printf("El grupo PIE y AIE NO se encuentran ambos activos\n");
            }
        }

        if (i == 12) {
            if ((actual->dato & 0x40) != 0) {
                printf("PF activo\n");
            } else {
                printf("PF inactivo\n");
            }

            if ((actual->dato & 0x20) != 0) {
                printf("AF activo\n");
            } else {
                printf("AF inactivo\n");
            }
        }
        i++;
        actual = actual->siguiente;
    }
}
