/*
Pregunta:
Explicar que es un sistema embebido y mencionar 2 ejemplos x oueden encontrarse

Un sistema embebido es una definicion para aparatos electronicos que realizan todas
sus funciones de procesamiento, memoria, I/O, desde el chip mismo.
Son simples en funcionamiento, baja complejidad, usualmente estan ligados de tareas
sencillas, como sensores, luces electronicas, o gadgets para smart home.

Un ejemplo muy comun de sistema embebido es un arduino, y tambien lo es una lampara
inteligente.

Esto significa que el sistema embebido es si o si una PC de baja complejidad?
No.

Los Sist.Emb son usados para realizar tareas con minima interfaz maquina - humano,
si el cerebro de un humano es una computadora, el cerebro de una hormiga es un S.E.
Hay tareas y acciones que no requieren de mucho procesamiento, y para eso son importantes.
Keep it simple
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    unsigned char vectorchar; 
    int posicion;            
    struct nodo* sig;   
} nodo;

typedef struct {
    nodo* prim;
    nodo* ult;  
} ListaEnlazada;



//Ordenar assciii
void insertar_ordenado(ListaEnlazada* lista, unsigned char valor, int posicion) {
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->vectorchar = valor;
    nuevo->posicion = posicion;

    //Extraido de ejs classe//
    if (lista->prim == NULL || lista->prim->vectorchar > valor) {
        // Lista vacía o primer elemento > nuevo.
        nuevo->sig = lista->prim;
        lista->prim = nuevo;
    } else {
        nodo* aux = lista->prim;
        while (aux->sig != NULL && aux->sig->vectorchar <= valor) {
            aux = aux->sig;
        }
        // Inserta el nuevo entre aux y aux->sig.
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }
}


//Mostrar en char y Hex y pocision

void mostrarListaEnlazada(ListaEnlazada* lista) {
    nodo* actual = lista->prim;
    if (actual == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    printf("\n La lista:\n");
    while (actual != NULL) {
        printf("Caracter: %c, posicion: %d\n", actual->vectorchar, actual->posicion + 1);
        actual = actual->sig;
    }
}


void mostrarListaEnlazadaHex(ListaEnlazada* lista) {
    nodo* actual = lista->prim;
    if (actual == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    printf("\nLA lista:\n");
    while (actual != NULL) {
        printf("Caracter: %c || En Hexagesimal: (0x%02X) || Posicion: %d\n", actual->vectorchar, actual->vectorchar, actual->posicion + 1);
        actual = actual->sig;
    }
}

// Función para buscar y eliminar caracteres con bits 4 y 5 menos significativos iguales a 1 y espacios.
void buscar_eliminar_caracteres(ListaEnlazada* lista) {
    nodo* actual = lista->prim;
    nodo* anterior = NULL;
    while (actual != NULL) {
        unsigned char mascara = 0b00001100; // BIT 4 y 5 SIENDO 6 y 7 los ultimos dos
        if ((actual->vectorchar & mascara) == mascara || actual->vectorchar == ' ') {
            //Lo previo elimina el char, espacio!//
            //El espacio INDIVIDUAL tiene ascii//
            if (anterior == NULL) {
                lista->prim = actual->sig;
            } else {
                anterior->sig = actual->sig;
            }
            nodo* temp = actual;
            actual = actual->sig;
            free(temp);
        } else {
            anterior = actual;
            actual = actual->sig;
        }
    }
}


int main() {

    //para el while//
    int salida = 0;
    int num;
    const char* cad = "APRENDIENDO A PROGRAMAR EN LENGUAJE C";
    unsigned char* p = (unsigned char*)cad;

    printf("Paz Lieghton Final Setiembre 15\n");
    int longitud;
    longitud = strlen(cad);
    printf("Longitud de de entrada: %d\n", longitud);

    ListaEnlazada lista;
    lista.prim = NULL;
    lista.ult = NULL;

    //menu//

    while (!salida) {
        printf("\n\nMenu:\n");
        printf("1. Lista simple, insertar vector ordenado por el int de cada char\n");
        printf("2. Buscar en lista los que tengan LSB 5 y 4 activos, eliminar espcaios \n");
        printf("3. Exit\n");
        printf("Ingrese Numero ");
        scanf("%d", &num);

        switch (num) {
            case 1:
                printf("Elegiste 1\n");


                nodo* actual = lista.prim;
                while (actual != NULL) {
                    nodo* sig = actual->sig;
                    free(actual);
                    actual = sig;
                }

                ListaEnlazada lista;
                lista.prim = NULL;
                lista.ult = NULL;
                //Esto ultimo es importante, borra la lista cada vez que apreto 1, hace posible que se repita//

                for (int i = 0; i < longitud; i++) {
                    insertar_ordenado(&lista, p[i], i);
                }

                printf("\nLista ordenada por valor ASCII:\n");
                mostrarListaEnlazada(&lista);
                break;
            case 2:
                printf("Elegiste 2\n");

                buscar_eliminar_caracteres(&lista);
                printf("\nLista después de eliminar caracteres con bits 4 y 5 menos significativos iguales a 1 y espacios:\n");
                mostrarListaEnlazadaHex(&lista);

                break;
            case 3:
                printf("Elegiste 3\n");
                printf("Saliendo...\n");
                salida = 1;
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
        printf("\n");
    }

    // Limpieza de memoria liberando nodos asignados.
    printf("\nLIMPIANDO...\n");

    nodo* actual = lista.prim;
    while (actual != NULL) {
        nodo* sig = actual->sig;
        free(actual);
        actual = sig;
    }
    return 0;
}

