#include <stdio.h>

int main(){
  int a = {5, 15, 34, 54, 14, 2, 52, 72};
  int *p = &a [1], *q = &a [5];

  printf("Direccion de p: %p\n", p);
  printf("Valor de p: %d\n", *p);
  printf("Direccion de q: %p\n", q);
  printf("Valor de q: %d\n",*q);

  printf("%d \n",*(p+3));//14 a[5]
  printf("%d \n",*(q-3));//34 a[2]
  printf("%d \n", (q-p));//Direccion de q menos p a 4 de distancia
  //aparentemente deberia ser 10


  return 0;
}
