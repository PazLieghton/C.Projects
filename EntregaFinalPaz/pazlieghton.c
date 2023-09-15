#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define una estructura de nodo para la lista enlazada para almacenar caracteres y posiciones.
typedef struct nodo {
    unsigned char vectorchar; // Carácter
    int posicion;             // Posición
    struct nodo* siguiente;   // Puntero al siguiente nodo
} nodo;

// Define una estructura de lista enlazada para llevar un registro de los primeros y últimos nodos.
typedef struct {
    nodo* primero; // Puntero al primer nodo
    nodo* ultimo;  // Puntero al último nodo
} ListaEnlazada;

// Función para insertar un nuevo nodo al final de la lista enlazada (FIFO).
void insertar_fifo(ListaEnlazada* lista, unsigned char vectorchar, int posicion) {
    // Asigna memoria para un nuevo nodo.
    nodo* nuevoNodo = (nodo*)malloc(sizeof(nodo));
    if (nuevoNodo == NULL) {
        printf("Fallo en la asignación de memoria.\n");
        exit(1);
    }
    // Establece el carácter, la posición y el puntero siguiente del nuevo nodo.
    nuevoNodo->vectorchar = vectorchar;
    nuevoNodo->posicion = posicion;
    nuevoNodo->siguiente = NULL;

    // Si la lista está vacía, hace que el nuevo nodo sea el primero y el último.
    if (lista->primero == NULL) {
        lista->primero = nuevoNodo;
        lista->ultimo = nuevoNodo;
    } else {
        // De lo contrario, agrega el nuevo nodo al final de la lista y actualiza el puntero último.
        lista->ultimo->siguiente = nuevoNodo;
        lista->ultimo = nuevoNodo;
    }
}

// Función para mostrar el contenido de la lista enlazada.
void mostrarListaEnlazada(ListaEnlazada* lista) {
    // Comienza desde el primer nodo.
    nodo* actual = lista->primero;

    if (actual == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    printf("\nContenido de la lista:\n");
    // Recorre la lista e imprime el carácter y la posición de cada nodo.
    while (actual != NULL) {
        printf("Vector: %c, Posición: %d\n", actual->vectorchar, actual->posicion + 1);
        actual = actual->siguiente;
    }
}

int main() {
    int num;
    int salir = 0;
    const char* cad = "El triunfo fue PERDER, la derrota fue GANAR.";
    unsigned char* p = (unsigned char*)cad;

    printf("Paz Lieghton Final Agosto 5\n");

    int longitud;
    longitud = strlen(cad);
    printf("Longitud de la cadena de entrada: %d\n", longitud);

    ListaEnlazada lista;
    lista.primero = NULL;
    lista.ultimo = NULL;

    while (!salir) {
        printf("\n\nMenú:\n");
        printf("1. Almacenar los datos de 'cad' en una lista y mostrarla (COMPLETO!)\n");
        printf("2. Almacenar letras minúsculas en un archivo 'filtrado.dat' (COMPLETO!)\n");
        printf("3. Mostrar valores con al menos 3 bits encendidos, su conteo y el porcentaje de bits encendidos (Falta la máscara con 3 bits como mínimo)\n");
        printf("4. Salir\n");
        printf("Ingrese un número: ");
        scanf("%d", &num);

        switch (num) {
            case 1:
                printf("\nElegiste 1.\n");
                if (lista.primero == NULL) {
                    printf("\nLa lista está vacía... creando...\n");
                    for (int i = 0; i < longitud; i++) {
                        insertar_fifo(&lista, p[i], i);
                    }
                    mostrarListaEnlazada(&lista);
                } else {
                    mostrarListaEnlazada(&lista);
                }
                break;
            case 2:
                printf("\nElegiste 2. Aquí están las letras minúsculas y sus valores ASCII válidos:\n");

                if (lista.primero == NULL) {
                    printf("La lista no ha sido generada. Debes seleccionar la opción 1 primero para generarla.\n");
                    break;
                }

                FILE* archivo = fopen("filtrado.dat", "wb");
                if (archivo == NULL) {
                    printf("No se pudo crear el archivo.\n");
                    break;
                }

                printf("\n\n");
                nodo* subLista = lista.primero;

                if (subLista == NULL) {
                    printf("La sublista de letras minúsculas está vacía.\n");
                }

                while (subLista != NULL) {
                    if (subLista->vectorchar >= 'a' && subLista->vectorchar <= 'z') {
                        printf("Almacenado: %c ", subLista->vectorchar);
                        unsigned char vectorchar = subLista->vectorchar;
                        fwrite(&vectorchar, sizeof(unsigned char), 1, archivo);
                    }
                    subLista = subLista->siguiente;
                }

                fclose(archivo);
                printf("La sublista de letras minúsculas se ha almacenado en el archivo 'filtrado.dat'.\n");
                break;
            case 3:
                printf("Este es el vector en binario:\n");

                nodo* actual = lista.primero;
                printf("\nElegiste 3. Mostrar valores con al menos 3 bits encendidos.\n");
                int contar0 = 0, contar1 = 0;
                while (actual != NULL) {
                    unsigned char mascara = 0b10000000;
                    printf(" %c - ", actual->vectorchar);
                    for (int i = 0; i < 8; i++) {
                        printf("%d", (actual->vectorchar & mascara) ? 1 : 0);
                        if (actual->vectorchar & mascara)
                            contar1++;
                        else
                            contar0++;
                        mascara >>= 1;
                    }
                    actual = actual->siguiente;
                }
                printf("\nEn el vector, hay %d valores con bits encendidos y %d valores con bits apagados.\n", contar1, contar0);
                printf("El porcentaje de bits encendidos en todo el vector es del %d por ciento.\n", (contar1 * 100) / (contar0 + contar1));
                break;
            case 4:
                printf("\nSaliendo...\n");
                salir = 1;
                break;
            default:
                printf("\nOPCIÓN INVÁLIDA.\n");
                break;
        }

        printf("\n");
    }

    // Limpieza de memoria liberando nodos asignados.
    printf("\nLIMPIANDO...\n");

    nodo* actual = lista.primero;
    while (actual != NULL) {
        nodo* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }

    return 0;
}