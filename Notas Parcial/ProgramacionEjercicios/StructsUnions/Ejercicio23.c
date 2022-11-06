#include <stdio.h>
#include <math.h>

struct puntos{
  float punto1x;
  float punto2x;
  float punto1y;
  float punto2y;
}puntos;

struct vectores{
  int vector1x;
  int vector1y;
  int vector2x;
  int vector2y;
}vectores;


int main(){
  int imp;
  float euclideanax, euclideanay;
  printf("Ingrese 1 para suma euclideana de puntos\n");
  printf("Ingrese 2 para la suma vectorial de dos vectores: ");
  scanf("%d",&imp);
  switch(imp){
    case 1:
      printf("\nSeleccionaste suma Euclideana");
      printf("\nIngrese el x de Punto 1: ");
      scanf("%f",&puntos.punto1x);
      printf("\nIngrese el y de Punto 1: ");
      scanf("%f",&puntos.punto1y);
      printf("\nIngrese el x de Punto 2: ");
      scanf("%f",&puntos.punto2x);
      printf("\nIngrese el y de Punto 2: ");
      scanf("%f",&puntos.punto2y);
      euclideanax = pow((sqrt((puntos.punto1x * puntos.punto2x))),2);
      euclideanay = pow((sqrt((puntos.punto1y * puntos.punto2y))),2);
      printf("La distancia euclideana en x es %f\n",euclideanax);
      printf("La distancia euclideana en y es %f\n",euclideanay);
      break;
    case 2:
      printf("\nSelccionaste suma VectorialPIJAZO");

      break;
    default:
      break;
  }
  return 0;
}
