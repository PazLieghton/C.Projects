#include <stdio.h>

int main (){
  int x = 3;
  int *p1;
  void *p2;
  int *p3;

  p1 = &x;
  printf("el valor de x es %d \n", *p1);
  p2 = &x;

//CLAVE CONVERSION DE VOID A TIPO INT//
  printf("el valor de x es %d \n", *(int*) p2);

//  printf("el valaor apuntado por p3 es %p \n", *p3);
//No asignamos memoria propia, puntero p3 apunta a memoria inaccesible//
  return 0;
}
