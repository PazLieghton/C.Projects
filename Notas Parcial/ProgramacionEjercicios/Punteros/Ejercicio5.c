#include <stdio.h>
#include <stdlib.h>
#define MAX 100


double* max (double *v, int cant){
  int i;
  double *max;
  if (cant = 0){
    return NULL;
  }

//  if(cant = 1){
//    max = &v[0];
//    return max;
//  }

  else{
    for(i=0;i<cant;i++){
      if(v[0]<v[i]){
        v[0] = v[i];
      }
      max = &v[0];
    }
    return max;
  }
}

int main(){
  double v[MAX];
  int size,i;


  printf("Ingrese el sizes:\n");
  scanf("%d",&size);

  switch (size) {
    case 0:
      max(v,size);
      exit(0);

    default:
      for(i=0;i<size;i++){
        printf("Ingrese el valor del vector en posicion %d:  ",i+1);
        scanf("%lf",&v[i]);
      }
  }
printf("La direccion del valor mayor es %p",max(v,size));
printf("\nEl valor mayor es %d",*(max(v,size)));

return 0;
}
