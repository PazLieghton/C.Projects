#include <stdio.h>
#include <stdlib.h>

int main(){
  int *v;
  int r,i;
  //Inicializamos el archivo//
  //La primera lectura no usa memoria//
  //Solo cuenta longitud vector//
  FILE *f;
  f = fopen("vector.dat","rb");
  if (f == NULL){
    printf("No existe archivo");
  }
  int longitud,longitudbytes;
  fseek(f,0,SEEK_END);
  longitudbytes = ftell(f);
  //longiudbytes al usar ftell devuelve el int en tipo long//
  longitud = longitudbytes / sizeof(long);
  printf("%d\n",longitud);
  printf("%d\n",longitudbytes);
  //Esta parte comienza poniendo un malloc al vector de lectura//
  //Leemos mientras asignamos valores a v[i]//
  v = (int*) malloc (sizeof(int) * longitud);
  //vector, longitud bloques//
  for (i = 0; i < longitud; i++){
    r = fread(v+i, sizeof(int),1,f);
    v[i]=r;
    printf("El vector en pos %d es: %d\n", i + 1, v[i]);
  }
  //Leemos v[i]//



  return 0;
}
