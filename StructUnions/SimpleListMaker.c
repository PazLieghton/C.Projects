// STRUCTS EJ - 1//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ESCRITURA//
struct lista
{
    int legajo;
    char nombre[20];
    float promedio;
}s;//Hago Typedef s//


int main ()
{
    int n, i;
    float prom;
    char nom[100];
    FILE *outfile;
    //Fopen Estudiantes.dat//
    outfile = fopen ("estudiantes.dat", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nOPENERROR\n");
        exit (1);
    }

    printf("Ingrese cantidad de alumnos: \n");
    scanf("%d", &n);
    printf("....\n");

    for (i = 1; i < n + 1; i++)
    {
        printf("Legajo:\n");
        scanf("%d", &s.legajo);
        printf("Nombre:\n");
        scanf("%s", &s.nombre);
        printf("\nPromedio:\n");
        scanf("%f", &s.promedio);
        printf("\n....");
        printf("\nLegajo: %d Nombre : %s Promedio %f\n",s.legajo,s.nombre,s.promedio);
        fwrite (&s, sizeof(s), 1, outfile);
    }

    if(fwrite != 0)
        printf("LISTO!\n");
    else
        printf("WERROR\n");

    fclose (outfile);
    return 0;
}
