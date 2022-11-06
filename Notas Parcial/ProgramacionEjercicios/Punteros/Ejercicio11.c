#include <stdio.h>

struct mi_estructura{
  char a, b;
  int c;
  int e[5];
};

int main(){
  int i;
  struct mi_estructura me;
  struct mi_estructura *p = &me;

  me.a = 'h';//Comillas simples char
  me.b = 'a';
  me.c = 7;
  for (i = 0;i<5;i++){
    me.e[i]=i;
  }


  printf("\n Parte a p->b: %c\n", p->b); //Devuelve Null a) es verdadero
  //AL insertar nuestro char nos devuelve el valor de char me.b = 'a'
  printf("\n Parte b p->e[3]: %d\n", p->e[3]); //Devuelve Null b) es falso
  // -> deberia devolver datos//
  printf("\n Parte c (*p).a: %d\n", (*p).a); //Devuelve la direccion ascii de h 104

  //Consigna de d es (*p.b) MAL, deberia ser *(p).b o p->b
  printf("\n Parte d *p.b %d\n", p->b); //Sin parentesus se debe hacer con flecha ->

  printf("\n Parte e me.c %d\n", me.c); //Por teoria de structs

  //Consigna es p.c MAL
  printf("\n Parte f p.c %d\n", p->c); //p debe usar flecha en este caso

  return 0;
}
