#include <stdio.h>

int main(){

char c = 'z';
char *p = &c;
//La direccion p apunta a la direccion ASCII de el ultimo char en string//
//p sin puntero apunta a su direccion de memoria de c//
printf("El p, %p",&p);
printf("El *p, %d",*p);

return 0;

}
