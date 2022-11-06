//Structs EJercicio 1//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct lista
{
    int neurona;
    double activacion;
}s;//Hago Typedef s//

int main ()
{
    int n, i;
    float prom;
    char nom[100];
    FILE *outfile;
    //Fopen Estudiantes.dat//
    outfile = fopen ("neuronas.dat", "wb");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nOPENERROR\n");
        exit (1);
    }

    printf("Ingrese la cantidad de neuronas: \n");
    scanf("%d", &n);
    printf("....\n");

    for (i = 1; i < n + 1; i++)
    {
        printf("Neurona:\n");
        scanf("%d", &s.neurona);
        scanf("%le", &s.activacion);
        printf("\nNeurona: %d Nivel Act : %le\n",s.neurona,s.activacion);
        fwrite (&s, sizeof(s), 1, outfile);
    }

    if(fwrite != 0)
        printf("LISTO!\n");
    else
        printf("WERROR\n");

    fclose (outfile);
    return 0;
}
