#include <stdio.h>

struct {
  union {
    char a, b;
    int c;
  }d;
int e [5];
}f,*p = &f,*q = &d; //En struct se puede llamar puntero

int main(){
  int i;
  //Primero agregamos datos al struct y su union contenida//
  f;

  f.d.a = 'h';//Comillas simples char
  f.d.b = 'a';
  f.d.c = 17;
  for (i = 0;i<5;i++){
    f.e[i]=i;
  }
  printf("Parte a p->b: %c\n", p->q->b); //Devuelve Null a) es verdadero
  //NO FUNCIONA LA FLECHA PORQUE PASO DE STRUCT A UNION


  return 0;
}
