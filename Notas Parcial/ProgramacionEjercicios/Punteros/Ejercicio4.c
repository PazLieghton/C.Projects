#include <stdio.h>

//EJ 4 - Pointers//

int impares (int *v, int tam){
  int i = 0, count = 0;
  for (i =0; i < tam; i++){
    if(*(v+i) % 2 /*Division Enteros*/ == 1){
      count ++;
    }
//Recordemos *(v) es equivalente a v[0] y, si queremos recorrer
//El vector con este for necesitamos *(v+1) = v[i]
  }
  return count;
}



int main(){

  int v[10] = {1,2,3,4,5,6,7,8,9,10};
  int size,a;

  //Esto va a devolver el tamanio en bytes del vector, en este caso
  //Va a devolver 40 byes que es la longitud real del vector pero no
  //de sus componentes interiores que son 10
  printf ("El sizeof %ld\n", sizeof(v));
  //Debemos entonces tomar el *v, que es equivalente a  *v = v[10]
  //Esto va a retornar el sizeof de v[0] que es 4 bytes
  //Al dividir el sizeof(v) que es 40 por el sizeof (*v) que es 4
  //Tendremos el tamanio real del vector
  printf ("El sizeof %ld\n", sizeof(*v));
  //Llamamos size a division sizeof(v) / {sizeof(*v) = sizeof(v[10])}
  size = (sizeof(v)/sizeof(*v));
  a = impares(v,size);

  printf ("\n\n\nLa cantidad de impares es %d",a);
  return 0;
}
