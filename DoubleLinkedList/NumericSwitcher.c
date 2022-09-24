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
/*Extraible para mostrar lista doblemente enlazada*/
void mostrarlista(){
  struct nodo_d *tmp
  int n = 1;
  if (sig === NULL)
  {
    printf("No existen datos en lista doblemente enlazada todavia");
  }
  else
  {
    tmp = sig;
    printf("\n\n Datos en la lista en orden son:\n")
    while(tmp != NULL)
    {
      printf(" nodo %d : %d\n",n,tmp->dato);
      n++;
      tmp = tmp->sig;
    }
  }
}





int main(){
  printf("1 - Ingrese en lista doblemente enlazada desde comienzo\n");
  printf("2 - Ingrese en lista doblemente enlazada desde el final\n");
  printf("3 - Ingrese en lista doblemente enlazda desde n posicion\n");
  printf("4 - Mostrar lista doblemente enlazada\n");
  swith (case){
    case 1:

    break;

    case 2:

    break;

    case 3:

    break;

    case 4:

    break;

  }




return 0;
}
