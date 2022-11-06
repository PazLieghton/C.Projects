#include <stdio.h>

int main(){
int matriz[3][3];
int i;
int j;


int *p = &matriz[3][3];

for (i=0; i<3 ;i++){
  for (j=0; j<3 ; j++){
    printf("Ingrese los valores de matriz\n");
    printf("En fila %d: y Columna: %d:  ",i+1,j+1);
    scanf("%d",&matriz[i][j]);
  }
}

for (i=0; i<3 ;i++){
  for (j=0; j<3 ; j++){
    printf("%d    ",matriz[i][j]);
  }
  printf("\n");
}

printf("\nDevolvemos matriz [1][1] con punteros: ");
printf("%d\n",*(*(matriz+1)+1));

for (i = 0; i < 3; i++){
  for (j = 0; j<3; j++){
    if (i == j){
      printf ("%d ",*(*(matriz+i)+j));
    }
  }
}
return 0;
}
