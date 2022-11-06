#include <stdio.h>

int main(){
  int *p;
  int i;
  int k;
  i = 42;
  k = i;
  p = &i;

  printf("Numero %d: \n",k);
  printf("Puntero p*: %d",*p);
  printf("Puntero p: %p\n",p);
  //Para obtener la direccion de memoria de &i es necesario llamar p en//
  //scanf con %p//
  *p = 75;
  printf("Imprimimos dato de i: %d",i);
  return 0;
}
