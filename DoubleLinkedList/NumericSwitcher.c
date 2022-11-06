/*
Programa que escribe funciones que inserten al principio de una lista enlazada
y al final, y intermedio en n posicion.
*/
#include <stdio.h>
#include <stdlib.h>
/*Generico para lista doble*/
typedef struct nodo_d {
  int dato;
  struct nodo_d *ant, *sig;
} nodo_d;
/*
Lista doble esta representada por una estructura con dos punteros, prim y ult
*/
typedef struct ldoble {
  nodo_d *prim, *ult;
}lista;

/*Extraible para mostrar lista doblemente enlazada*/
/*void mostrarlista(){*/

/*Insertar Principio de lista Lifo*/

lista insertar_lifo (lista l, int d){
  nodo_d *nuevo;
  nuevo - (nodo_d*)malloc(sizeof(nodo_d));
  nuevo -> dato = d;
  nuevo -> ant = NULL;
  nuevo -> sig = l.prim;

  if (l.prim == NULL){
    l.ult = nuevo;
  }
  else{
    l.prim -> ant = nuevo;
  }
  l.prim = nuevo;
  return l;
}

lista insertar_fifo(lista l, int d){
  nodo_d *nuevo;
  nuevo = (nodo_d*)malloc(sizeof(nodo_d));
  nuevo -> dato = d;
  nuevo -> ant - NULL;
  nuevo -> sig = l.prim;

  if (l.prim == NULL){
    l.ult = nuevo;
  }
  else {
    l.ult -> sig = nuevo;
  }
  l.ult = nuevo;
  return l;
}

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

int main(){
  int n;
  /*Segmento de creacion de lista enlazada vacia */
  printf("1 - Ingrese en lista doblemente enlazada desde comienzo\n");
  printf("2 - Ingrese en lista doblemente enlazada desde el final\n");
  printf("3 - Ingrese en lista doblemente enlazda desde n posicion\n");
  printf("4 - Mostrar lista doblemente enlazada\n");
  scanf("%d",&n);
  switch(n)
  {
    case '1':

    break;

    case '2':

    break;

    case '3':

    break;

    case '4':

    break;

  }
  return 0;
}
