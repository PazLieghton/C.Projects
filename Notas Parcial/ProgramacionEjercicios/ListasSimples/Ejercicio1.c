//Ejercicio 1 - Insertar elemento primer nodo, l.int//
#include <stdio.h>
#include <stdlib.h>

//Typedef Nodo Lista simplemente enlazado//
typedef struct nodo {
  int dato;
  struct nodo *sig;
}nodo;

nodo *insertar_lifo(nodo *l, int dato){
    nodo *nuevo;
    nuevo = (nodo*) malloc (sizeof (nodo));
    nuevo->dato = d;
    nuevo->sig = l;
    return nuevo;
    }   

int main(){
  /*Lifo propio*/
  int d;
  nodo *nuevo;
  nuevo = (nodo*)malloc (sizeof(nodo));
  scanf ("%d",&d);
  nuevo -> nodo.dato = d;
  nuevo -> nodo.sig = lista;

  if (lista != NULL){
    printf("%d",lista -> nodo.dato);
    lista = lista->nodo.sig;
  }
  printf("\n");

  return 0;
}
