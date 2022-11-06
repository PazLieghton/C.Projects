#include <stdio.h>

int main()
{
  int i;
  int c;
  int largo, comienzo,final;
  char palabra[69],invertida[69];
  printf("Ingrese su string en minusculas: ");
  scanf("%s",palabra);
  for (c = 0;palabra[c] != '\0';++c);
  printf("Este es el sizeof de su string: %d\n",c);
  largo = c;
  printf("Vamos a probar que ingresaste minusculas\n");
  for (i = 0; palabra[i]; i++){
    if (palabra[i] > 'z' || palabra[i] < 'a'){
      printf("\n");
      return 0;
    }
  }
  //Programa Para Cambiar el ascii//
  for (i=0;i<c;i++){
    palabra[i] = palabra[i] - 32;
  }

  printf("En mayusculas es %s\n",palabra);
  //ORDEN INVERSO//
  final = largo - 1;
  for (comienzo = 0; comienzo < largo; comienzo++){
    invertida[comienzo] = palabra[final];
    final--;
  }
  invertida[comienzo] = '\0';
  printf("\n\nEN ORDEN INVERSO ES: %s\n",invertida);

  return 0;
}
