#include <stdio.h>

int main()
{
    FILE *fp;
    char filename[5];
    char writestr[5];

    //Leer Archivo
    printf("Enter a filename :");
    gets(filename);

    //Lee strings para escribir
    printf("Ingrese Strings :");
    gets(writestr);

    //FOPEN
    fp = fopen(filename,"w+");

    //Si se abre archivo se escribe
    if ( fp )
    {
        fputs(writestr,fp);
    }
    else
    {
        printf("Failed to open the file\n");
    }
//Cerramos Archivo
    fclose(fp);
    return(0);
}
