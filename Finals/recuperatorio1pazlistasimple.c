#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    char valor;
    int posicion;
    struct Nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* primero;
    Nodo* ultimo;
} ListaSimple;

void insertar_fifo(ListaSimple* lista, char valor, int posicion) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->posicion = posicion;
    nuevoNodo->siguiente = NULL;

    if (lista->primero == NULL) {
        lista->primero = nuevoNodo;
        lista->ultimo = nuevoNodo;
    } else {
        lista->ultimo->siguiente = nuevoNodo;
        lista->ultimo = nuevoNodo;
    }
}

void mostrarLista(ListaSimple lista) {
    Nodo* actual = lista.primero;

    if (actual == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    printf("\nContenido de la lista:\n");
    while (actual != NULL) {
        printf("Vector: %c, Posición: %d\n", actual->valor, actual->posicion);
        actual = actual->siguiente;
    }
}

void mostrarListaInversa(Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }
    mostrarListaInversa(nodo->siguiente);
    printf("Vector: %c, Posición: %d\n", nodo->valor, nodo->posicion);
}

void mostrarNodoSeleccionado(Nodo* nodo, int busc) {
    if (nodo == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    int contador = 1;
    while (nodo != NULL) {
        if (contador == busc) {
            printf("\nContenido del vector en posición %d\n", busc);
            printf("Vector: %c, Posición: %d\n", nodo->valor, nodo->posicion);
            return;
        }
        nodo = nodo->siguiente;
        contador++;
    }

    printf("Número de nodo no válido.\n");
}

int main() {
    const char* cadena = "NO TE LO PUEDO EXPLICAR porque no vas a entender";
    int longitud = strlen(cadena);

    ListaSimple lista;
    lista.primero = NULL;
    lista.ultimo = NULL;

    for (int i = 0; i < longitud; i++) {
        insertar_fifo(&lista, cadena[i], i);
    }

    int opcion;
    int salir = 0;

    while (!salir) {
        printf("\n\nMenú:\n");
        printf("1. Guardar los datos en una lista simplemente enlazada y mostrarla (COMPLETO)\n");
        printf("2. Mostrar los datos de la lista en orden inverso (COMPLETO)\n");
        printf("3. Mostrar el contenido de un nodo seleccionado (COMPLETO)\n");
        printf("4. Salir\n");
        printf("Ingrese un número: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Elegiste 1.\n");
                mostrarLista(lista);
                break;
            case 2:
                printf("\nElegiste 2. Mostrar los datos en orden inverso\n");
                if (lista.primero == NULL) {
                    printf("La lista simplemente enlazada no existe. Primero debes seleccionar la opción 1 para generarla.\n");
                    break;
                }
                printf("\nContenido de la lista en orden inverso:\n");
                mostrarListaInversa(lista.primero);
                break;
            case 3:
                printf("\nElegiste 3. Mostrar el contenido de un nodo seleccionado\n");
                if (lista.primero == NULL) {
                    printf("La lista simplemente enlazada no existe. Primero debes seleccionar la opción 1 para generarla.\n");
                    break;
                }
                printf("\nIngrese el número del nodo a buscar (1 para el primer nodo): ");
                int busc;
                scanf("%d", &busc);
                mostrarNodoSeleccionado(lista.primero, busc);
                break;
            case 4:
                printf("Saliendo...\n");
                salir = 1;
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
        printf("\n");
    }

    Nodo* auxiliar = lista.primero;
    while (auxiliar != NULL) {
        Nodo* siguiente = auxiliar->siguiente;
        free(auxiliar);
        auxiliar = siguiente;
    }

    return 0;
}
