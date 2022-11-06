#include<stdio.h>
#include<stdlib.h>
#define MAX 100
FILE *f;


struct alumnos{
  int legajo;
  char nombre[20];
  float promedio;
};

void muestro(struct alumnos a){
  printf ("legajo: %d - nombre: %s - promedio %.2f\n", a.legajo, a.nombre, a.promedio);
}

void muestro_lista(struct alumnos v[],int cant){
int i;

for(i=0;i<cant;i++)
    muestro(v[i]);
    fwrite (&v,sizeof(v[i]),1,f);
}


int main(){

int i = 0;
int leg;
struct alumnos vp[MAX];


printf("ingrese el legajo:\n");
scanf("%d",&leg);

while(leg>=0){
  vp[i].legajo=leg;
  printf("ingrese el nombre del alumno con legajo %d\n", leg);
  scanf("%s", vp[i].nombre);
  printf("ingrese el promedio\n");
  scanf("%f",&vp[i].promedio);

  i++;
  printf("ingrese el legajo:\n");
  scanf("%d",&leg);
}

//Parte de Texto//
int res;

f = fopen ("estudiantes.dat","w");
if (f == NULL){
  printf("\n Error al crear el archivo\n");
  return 1;
}

muestro_lista(vp,i);

res = fclose(f);
if (res !=0){
  printf("\nERROR DE CERRADO");
  return 2;
}

printf("\n ... Guardado exitoso");
return 0;
}
