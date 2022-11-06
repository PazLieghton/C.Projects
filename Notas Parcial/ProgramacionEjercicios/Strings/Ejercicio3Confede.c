#include <stdio.h>
#include <string.h>

char comparador(char palabra, char palabra2){

  char mayor[20];
  //char palabra[20];
  //char palabra2[20];

  if(strcmp(palabra,palabra2)<=0){
    strcpy(mayor,palabra);
  }
  else{
    strcpy(mayor,palabra2);
  }
  return (mayor);
}

int main(){
char mayor[20];
char palabra[20];
char palabra2[20];

printf("ingrese su palabra:\n");
fgets(palabra);
printf("ingrese su segunda palabra:\n");
fgets(palabra2);

//mayor = comparador(palabra,palabra2);
//puts(mayor);
return 0;

}
