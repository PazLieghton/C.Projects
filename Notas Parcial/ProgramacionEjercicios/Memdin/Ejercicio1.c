#include <stdio.h>
#include <stdlib.h>
int main(){
  int n,i;
  printf("Ingrese la cantidad de items para el vector: ");
  scanf("%d",&n);
  //Aloco memoria para el vector de longitud n//
  int *v;
  v = (int*) malloc (sizeof(int) * n);
  //Procedo a llenar el vector//
  for (i = 0; i < n; i++){
    printf("Ingrese el numero en posicion %d: ",i+1);
    scanf("%d",&v[i]);
  }
  //Muestro el vector
  for (i = 0; i< n; i++){
    printf("\nPos %d = %d\n",(i+1),v[i]);
  }
  //Inicializar el archivo//
  FILE *f;
  int w;
  f = fopen("vector.dat","wb");
  //Escribo el vector por completo//
  if (f != NULL){
    //sizeof (v)
      w = fwrite (v, sizeof(v),n,f);
      if (w != n){
        printf("Error Grabando");
      }
      if (fclose(f) != 0){
        printf("Error Cerrando");
      }
  }
  else{
    printf("Error creando");
  }
  //Fin archivo;
  free(v);
  //Libero vector porque ya esta escrito//
  return 0;
}
