/*
Ejercicio 1a y 1b listas dobles
Programa que permite agregar elementos al final o al principio de una lista doble y la recorre en ambos sentidos
Autor: David Lopez
Programación UNSAM
Año: 2020
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_d {
	float dato; /* Se decidio arbitrariamente usar float para el dato (podría ser cualuier tipo) */
	struct nodo_d *ant, *sig;
} nodo_d;

/* La lista doble esta representada por una estructura con 2 punteros: primero y ultimo */
typedef struct ldoble {
	nodo_d *prim, *ult;
} lista;

/* Inserta al principio del la lista */
lista insertar_lifo(lista l, float d) {
	nodo_d *nuevo;

	nuevo = (nodo_d*) malloc(sizeof(nodo_d));
	nuevo->dato = d;
	nuevo->ant = NULL;
	nuevo->sig = l.prim;

	if (l.prim == NULL) /* Lista vacia, l.prim y l.ult son NULL */
		l.ult = nuevo;
	else
		l.prim->ant = nuevo;
	l.prim = nuevo;
	return l;
}

/* Inserta al final del la lista, muy similar a insertar_lifo, ya que  */
/* la estructura de una lista doblemente enlazada es simetrica */
/* solo cambia ant por sig,y viceversa, prim por ult y viceversa */
lista insertar_fifo(lista l, float d) {
	nodo_d *nuevo;

	nuevo = (nodo_d*) malloc(sizeof(nodo_d));
	nuevo->dato = d;
	nuevo->sig = NULL;
	nuevo->ant = l.ult;

	if (l.prim == NULL) /* Lista vacia, l.prim y l.ult son NULL */
		l.prim = nuevo;
	else
		l.ult->sig = nuevo;
	l.ult = nuevo;
	return l;
}

/* Destruye la lista liberando la memoria ocupada por cada nodo */
lista destruir (lista l) {
	nodo_d *p, *aux;
	
	p = l.prim;
	while (p != NULL) {
		aux = p;
		p = p->sig;
		free (aux);
	}
	printf ("Lista destruida\n");
	l.prim = NULL;
	l.ult = NULL;
	return l;
}

int main() {
	nodo_d *p; /* Puntero para recorrer la lista */
	float f;
	lista l; /* La lista propiamente dicha */
	int modo; /* Como quiero insertar: lifo o fifo */

	/* Inicializo la lista */
	l.prim = NULL;
	l.ult = NULL;

	printf("Ingrese los datos (0 para terminar): ");
	scanf("%f", &f);
	while (f != 0) {
	    printf ("\nIngrese 1 para LIFO o 2 para FIFO: ");
	    scanf ("%d", &modo);
	    if (modo == 1)
		    l = insertar_lifo(l, f);
	    else
		    l = insertar_fifo(l, f);
	    printf("\nIngrese los datos (0 para terminar): ");
	    scanf("%f", &f);
	}

	printf("\nMuestro en orden ingresado\n"); /* Al derecho, desde el principio */
	for (p = l.prim; p != NULL; p = p->sig)
	    printf("Dato = %6.2f\n", p->dato);

	printf("Muestro en orden inverso\n"); /* Al reves, desde el final */
	for (p = l.ult; p != NULL; p = p->ant)
	    printf("Dato = %6.2f\n", p->dato);
	
	l = destruir (l);
	return 0;
}
