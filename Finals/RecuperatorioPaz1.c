/*
PAZ SOFIA LIEGHTON PEREIRA
Rec 1er parcial

Ej. 1) (80%) Parta de la siguiente línea de código en lenguaje C respetando mayúsculas y espacios:

unsigned char *r = (unsigned char*) "NO TE LO PUEDO EXPLICAR porque no vas a entender";

 Como usted sabrá por sus conocimientos adquiridos en esta asignatura, luego de la ejecución de esa línea, el puntero r puede utilizarse como un vector de valores de tipo unsigned char. Escriba un programa en C que presente un menú repetitivo con las siguientes opciones:

1.     Guardar los datos en una lista enlazada. Cada nodo debe contener un valor del vector, y además un segundo valor que indique a qué posición corresponde dentro del vector r (empezando en cero) y mostrar la lista. Si ya existía destruirla.

2.      Guardar los datos de la lista en un archivo binario llamado datos.bin, pero sin incluir el primer nodo ni el último.

3.      Mostrar los datos de la lista en orden inverso. No usar estructuras de datos adicionales a las ya usadas.

    Ingresando un número de nodo por teclado, mostrar el contenido de dicho nodo tomando el primer nodo como 1. No usar estructuras de datos adicionales a las ya usadas.
    Finalizar el programa.

Ej. 2) (20%) Si tiene que buscar un elemento en una lista del cual desconoce su posición ¿Será más rápido encontrarlo en una lista FIFO, LIFO, ordenada, doble o no hay diferencia? Justifique.


Pregunta Teorica
Si tiene que buscar un elemento en una lista del cual desconoce su posición ¿Será más rápido encontrarlo en una lista FIFO, LIFO, ordenada, doble o no hay diferencia? Justifique.
Entregue la respuesta mediante un comentario al principio del código entregado para el ejercicio 1).

Es más fácil dividir y conquistar, los algoritmos de búsqueda tienen distintos modos de hallar un ítem en particular.
Con una lista simplemente enlazada recorremos en una dirección, pero es como revolver un mazo de cartas y buscar el "uno de basto" una por una.
Una computadora puede dividir ese mazo de cartas y comparar dos pilas de cartas, o más, y para ello necesita recorrer los datos por los dos lados.

Aquí es cuando entra un tema de cómo procesa la información la computadora en sí.
Por ejemplo, mi laptop tiene un Core i5 6200U (Sí, necesito comprar una nueva), ¡tiene 2 núcleos y 2 hilos! Imagina que tengo una pila de cartas.
Mi PC puede perfectamente usar un programa que utilice los dos hilos, dividiendo la carta a la mitad y procesando las dos pilas a la misma velocidad.
Teóricamente, en el peor de los casos, el rendimiento aumenta aproximadamente el doble en comparación con una lista simple.

Pero, si tengo una PC con un solo núcleo, entonces ahí no importa qué tipo de lista use, simple o doble, ambas son teóricamente iguales.

Por cierto, FIFO, LIFO, cómo estén ingresados los datos no importa, no tiene nada que ver.
Es como decir que el orden de las cartas en el mazo no afecta a qué tan rápido encuentras la carta que buscas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vector {
    unsigned char vectorchar[100];
    int posicion;
    struct vector* ant, * sig;
} vector;

typedef struct ldoble {
    vector* prim, * ult;
} lista;

void insertar_fifo(lista* l, unsigned char vectorchar, int posicion) {
    vector* nuevoNodo = (vector*)malloc(sizeof(vector));
    nuevoNodo->vectorchar[0] = vectorchar;
    nuevoNodo->posicion = posicion;
    nuevoNodo->ant = NULL;
    nuevoNodo->sig = NULL;

    if (l->prim == NULL) {
        l->prim = nuevoNodo;
        l->ult = nuevoNodo;
    } else {
        nuevoNodo->ant = l->ult;
        l->ult->sig = nuevoNodo;
        l->ult = nuevoNodo;
    }
}

void mostrarLista(lista l) {
    vector* actual = l.prim;

    if (actual == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    printf("\nContenido de la lista:\n");
    while (actual != NULL) {
        printf("Vector: %c, Posición: %d\n", actual->vectorchar[0], actual->posicion);
        actual = actual->sig;
    }
}

void ordenarListaInversa(lista* l) {
    int intercambio = 1;
    vector* actual = l->prim;
    while (intercambio) {
        intercambio = 0;
        while (actual->sig != NULL) {
            if (actual->posicion < actual->sig->posicion) {
                vector* temp = actual->sig;
                actual->sig = temp->sig;
                temp->sig = actual;
                temp->ant = actual->ant;
                actual->ant = temp;
                if (temp->ant != NULL) {
                    temp->ant->sig = temp;
                }
                if (actual->sig != NULL) {
                    actual->sig->ant = actual;
                }
                if (l->prim == actual) {
                    l->prim = temp;
                }
                intercambio = 1;
            } else {
                actual = actual->sig;
            }
        }
        actual = l->prim;
    }
}

void REordenarListaInversa(lista* l) {
    int intercambio = 1;
    vector* actual = l->prim;
    while (intercambio) {
        intercambio = 0;
        while (actual->sig != NULL) {
            if (actual->posicion > actual->sig->posicion) {
                vector* temp = actual->sig;
                actual->sig = temp->sig;
                temp->sig = actual;
                temp->ant = actual->ant;
                actual->ant = temp;
                if (temp->ant != NULL) {
                    temp->ant->sig = temp;
                }
                if (actual->sig != NULL) {
                    actual->sig->ant = actual;
                }
                if (l->prim == actual) {
                    l->prim = temp;
                }
                intercambio = 1;
            } else {
                actual = actual->sig;
            }
        }
        actual = l->prim;
    }
}

void mostrarListaItem(lista l, int busc) {
    vector* actual = l.prim;
    int cont;
    if (actual == NULL) {
        printf("La lista está vacía. Favor Realizar el primer paso\n");
        return;
    }

    for (cont = 0; cont < (busc - 1); cont++) {
        actual = actual->sig;
    }

    printf("\nContenido del vector en posicion %d\n", busc);
    printf("Vector: %c, Posición: %d\n", actual->vectorchar[0], actual->posicion);
}

int main() {
    unsigned char *r = (unsigned char*) "NO TE LO PUEDO EXPLICAR porque no vas a entender";
    int a;
    a = strlen(r);
    printf("ESTA ES LA LONGITUD DEL VECTOR: %d\n", a);

    int num, i;
    int salida = 0;

    printf("\nEN PRIMERA INSTANCIA ESTOS SON LOS VALORES DEL VECTOR en UNSIGNED CHAR\n");
    for (i = 0; i < a; i++) {
        printf("%c", r[i]);
    }

    printf("\n\nEN PRIMERA INSTANCIA ESTOS SON LOS VALORES DEL VECTOR en int\n");
    for (i = 0; i < a; i++) {
        printf("%d ", r[i]);
    }

    lista l;
    l.prim = NULL;
    l.ult = NULL;
    unsigned char vectorchar;
    int posicion;

    while (!salida) {
        printf("\n\nMenu:\n");
        printf("1. Guardar los datos en una lista doblemente enlazada, y mostrarla (COMPLETO)\n");
        printf("2. Guardar los datos de la lista doblemente enlazada, excepto posicion 0 y 48 (COMPLETO Y FUNCIONA LECTOR TAMBIEN)\n");
        printf("3. Mostrar los datos de la lista en orden inverso. (COMPLETO USE COMPARANDO LAS POSICIONES)\n");
        printf("4. Ingresando un número de nodo por teclado, mostrar el contenido de dicho nodo tomando el primer nodo como 1.\n");
        printf("5. Exit\n");
        printf("Ingrese Numero ");
        scanf("%d", &num);

        switch (num) {
            case 1:
                printf("Elegiste 1.\n");
                if (l.prim == NULL) {
                    printf("\nLa lista esta vacia... creando...\n");
                    for (i = 0; i < a; i++) {
                        insertar_fifo(&l, r[i], i);
                    }
                } else {
                    printf("\n\n Vaciando la lista, ingresar de nuevo el programa 1 \n");
                    l.prim = NULL;
                    l.ult = NULL;
                    for (i = 0; i < a; i++) {
                        insertar_fifo(&l, r[i], i);
                    }
                }
                mostrarLista(l);
                break;
            case 2:
                printf("\n\nElegiste 2.\n");
                if (l.prim == NULL) {
                    printf("La lista doble no existe. Primero debes seleccionar la opción 1 para generarla.\n");
                    break;
                }

                FILE* archivo = fopen("datos.bin", "wb");
                if (archivo == NULL) {
                    printf("No se pudo crear el archivo.\n");
                    break;
                }

                vector* Sublista = l.prim->sig; // Saltar el primer nodo
                while (Sublista != NULL && Sublista->sig != NULL) { // Detenerse antes del último nodo
                    unsigned char vectorchar = Sublista->vectorchar[0];
                    int posicion = Sublista->posicion;

                    fwrite(&vectorchar, sizeof(unsigned char), 1, archivo);
                    fwrite(&posicion, sizeof(int), 1, archivo);

                    Sublista = Sublista->sig;
                }
                fclose(archivo);
                printf("La sublista ha sido guardada en el archivo 'datos.bin'.\n");
                break;
            case 3:
                printf("\n\nElegiste 3. Mostrar los datos en orden inverso\n");
                if (l.prim == NULL) {
                    printf("La lista doble no existe. Primero debes seleccionar la opción 1 para generarla.\n");
                    break;
                }
                ordenarListaInversa(&l);
                mostrarLista(l);
                REordenarListaInversa(&l);
                break;
            case 4:
                printf("\n\nElegiste 4.\n");
                if (l.prim == NULL) {
                    printf("La lista doble no existe. Primero debes seleccionar la opción 1 para generarla.\n");
                    break;
                }
                printf("\nIngrese el número del nodo a buscar: Recordar que 1 es en la posición vector 0:   ");
                int busc;
                scanf("%d", &busc);
                mostrarListaItem(l, busc);
                break;
            case 5:
                printf("Saliendo...\n");
                salida = 1;
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
        printf("\n");
    }

    vector* auxiliar = l.prim;
    while (auxiliar != NULL) {
        vector* siguiente = auxiliar->sig;
        free(auxiliar);
        auxiliar = siguiente;
    }

    return 0;
}
