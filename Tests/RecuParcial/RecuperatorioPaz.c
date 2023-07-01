/*
PAZ SOFIA LIEGHTON PEREIRA
Rec 1er parcial

Pregunta Teorica
Si tiene que buscar un elemento en una lista del cual desconoce su posición ¿Será más rápido encontrarlo en una lista FIFO, LIFO, ordenada, doble o no hay diferencia? Justifique.
Entregue la respuesta mediante un comentario al principio del código entregado para el ejercicio 1).

Es mas facil dividir y conquistar, los algoritmos de busqueda tienen distintos modos de hallar un item en particular.
Con una lista simplemente enlazada recorremos por una direccion, pero es como revolver un mazo de cartas y buscar el uno de basto una por una.
Una computadora puede dividir ese mazo de cartas y comparar dos pilas de cartas, o mas y para ello necesita recorrer los datos por los dos lados.

He aqui cuando entra un temita de como procesa la informacion la computadora en si.
Por ejemplo, mi laptop tiene una core i5 6200U (SI, tengo que comprar una) , tiene 2 cores 2 hilos!!!, imaginate que tengo una pila de cartas.
Mi pc puede perfectamente usar un programa que utiliza los dos hilos, dividiendo la carta a la mitad y procesando las dos pilas a la misma velocidad
Teoreticamente, en el peor de los casos la performance aumenta unas DOS VECES comparado a una lista simple.

Pero, si tengo una pc con un solo Core, entonces ahi no importa que tipo de lista uso, simple o doble las dos son teoreticamente las mismas.

Por cierto, fifo, lifo, como esten ingresado los datos no importa, no tiene nada que ver.
Es como decir como ordenas el mazo afecta que tan rapido hallas la carta que buscas.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Para hallar la longitud del string


//Usare lista doblemente enlzada para mas facilidad a la hora de mostrar el orden inverso//

typedef struct vector {
    unsigned char vectorchar[100];
    int posicion;//Desde cero//
    struct vector* ant, * sig;
} vector;

typedef struct ldoble {
    vector* prim, * ult;
} lista;


//Funciones Parte 1 USARE FIFO//
//Me base bastante en el primer parcial de mayo 20 2023 que reprobe//

void insertar_fifo(lista* l, unsigned char vectorchar, int posicion) {
    vector* nuevoNodo = (vector*)malloc(sizeof(vector));
    nuevoNodo->vectorchar[0] = vectorchar;
    nuevoNodo->posicion = posicion;
    nuevoNodo->ant = NULL;
    nuevoNodo->sig = NULL;

    if (l->prim == NULL) {
        l->prim = nuevoNodo;
        l->ult = nuevoNodo;
    }
    else {
        nuevoNodo->ant = l->ult;
        l->ult->sig = nuevoNodo;
        l->ult = nuevoNodo;
    }
}

//Vectorchar[0] muestra el caracter individual es vital
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

//Funcion para item 3//


//Este fue el mas dificil me base en mis apuntes y tenia que dar vuelta 2 lineas de codigo//

//El tema es que en la consigna mia yo guardaba la lista, asi que tuve que crear un programa que REORDENE//
//Asi no entra en conflictos con el item 3//
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
            }
            else {
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
            if (actual->posicion > actual->sig->posicion) { //Unica diferencia es en esta linea//
                vector* temp = actual->sig;
                actual->sig = temp->sig;
                temp->sig = actual;
                temp->ant = actual->ant;//Y esta linea//
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
            }
            else {
                actual = actual->sig;
            }
        }
        actual = l->prim;
    }
}
//Funcion para item 4 SIMIL A LA FUNCION MOSTRAR//

void mostrarListaItem(lista l,int busc) {
    vector* actual = l.prim;
    int cont;
    if (actual == NULL) {
        printf("La lista está vacía. Favor Realizar el primer paso\n");
        return;
    }

    for (cont = 0; cont < (busc - 1); cont++){
        actual = actual->sig;
    }

    printf("\nContenido del vector en posicion %d\n",busc);
    printf("Vector: %c, Posición: %d\n", actual->vectorchar[0], actual->posicion);
}

int main() {
    
    //Uso este vector de tipo unsigned char//
    unsigned char *r = (unsigned char*) "NO TE LO PUEDO EXPLICAR porque no vas a entender";
    
    //Creo un a, que recorre la longitud del vector unsigned char//
    int a;
    a = strlen(r);
    printf("ESTA ES LA LONGITUD DEL VECTOR: %d\n",a);


    int num,i;
    int salida = 0;

    printf("\nEN PRIMERA INSTANCIA ESTOS SON LOS VALORES DEL VECTOR en UNSIGNED CHAR\n");
    for (i = 0 ; i < a ; i++){
        printf("%c", r[i]);
    }
    
    //Ignora lo siguiente, consulte para hacer items en int y no era asi//
    printf("\n\nEN PRIMERA INSTANCIA ESTOS SON LOS VALORES DEL VECTOR en int\n");
    for (i = 0 ; i < a ; i++){
        printf("%d ", r[i]);
    }

    //Inicializo la lista//
    
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
                if (l.prim == NULL){
                printf("\nLa lista esta vacia... creando...\n");
                    for (i = 0 ; i < a ; i++){
                        insertar_fifo(&l,r[i],i);
                    }   
                }
                else {
                    printf("\n\n Vaciando la lista, ingresar de nuevo el programa 1 \n");
                    l.prim = NULL;
                    l.ult = NULL;
                }
                //TEST QUE USE PARA EL PARCIAL 2023 previo insertar_fifo(&l, "A", 0);
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


                vector* Sublista = (l.prim -> sig);
                while (Sublista != NULL & ((Sublista -> sig) != NULL) ) {
                    fwrite(Sublista, sizeof(vector), 1, archivo);
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
                //Invierto de nuevo porque preferi tocar la estructura asi no afecta el programa 4//
                REordenarListaInversa(&l);
                break;
            case 4:
                printf("\n\nElegiste 4.\n");
                if (l.prim == NULL) {
                    printf("La lista doble no existe. Primero debes seleccionar la opción 1 para generarla.\n");
                    break;
                }
                printf("\nIngrese el numero del nodo a buscar: Recordar que 1 es en la posicion vector 0:   ");
                int busc;
                scanf ("%d", &busc);
                //Al igual que el punto previo tengo que referirme al vecot//
                //vector* Sublista1 = (l.prim);
                //while (Sublista1 != NULL & ((Sublista1 -> sig -> posicion =! (busc-1) )))  {
                //    Sublista1 = Sublista1->sig;
                //}
                mostrarListaItem(l,busc);
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
        
    //Libero memoria lista doble vector
    vector* auxiliar = l.prim;
    while (auxiliar != NULL) {
        vector* siguiente = auxiliar->sig;
        free(auxiliar);
        auxiliar = siguiente;
    }

    return 0;
}
