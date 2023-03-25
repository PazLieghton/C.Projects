#include <stdio.h>
#include <stdlib.h>
#define MAX 1


struct person
{
    int legajo;
    char nombre[20];
    float promedio;
};

int main ()
{
    FILE *infile;
    struct person input;
    struct person arr[MAX];
    int i, n = 0, max;
    float arr1[100];
    infile = fopen ("estudiantes.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    printf("Los datos son los siguientes: \n");
    printf("LEGAJO || NOMBRE || PROMEDIO\n");

    while(fread(&arr, sizeof(struct person), 1, infile))
        for(i = 0; i < MAX; i++ )
            {
            printf("%d      %s      %.2f\n",arr[i].legajo, arr[i].nombre, arr[i].promedio);
            //arr1 copia del texto a local//
            arr1[n] = arr[i].promedio;
            n++;
            }
    fclose (infile);
    //Cerramos el archivo y hallamos el maximo del array//
    for(i = 0; i < n; i++ )
    {
        if (arr1[i] > max)
        {
            max  = arr1[i];
        }
    }
    //Para volver a trabajar con el struct debemos abrir El texto De nuevo//
    infile = fopen ("estudiantes.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    printf("El elemento maximo del struct es: %d.\n", max);
    //Ahora retornamos El Valor Mas alto Y quien le coresponde//
    while(fread(&arr, sizeof(struct person), 1, infile))
        for(i = 0; i < MAX; i++ )
        {
            if (arr[i].promedio == max)
            {
                printf("\n%s tiene el promedio mas alto, y su promedio es: %.2f",arr[i].nombre,arr[i].promedio);
            }
        }
    fclose (infile);
    return 0;
}
