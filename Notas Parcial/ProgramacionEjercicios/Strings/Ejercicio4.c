//P1 - Strings - EJ2\4//

#include <stdio.h>
#include <string.h>

//Bubble Sort//
//Lease MAIN//
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

int main()
{
    int i, j, k, length[5], arr[5];
    char a[5][100];

    printf("Ingrese sus 5 strings\n");
    for(i = 0; i < 5; ++i)
        scanf("%s[^\n]",a[i]);
    for (j = 0; j < 5; j++)
    {
        length[j] = strlen(a[j]);
    }
    for (k = 0; k< 5; k++)
    {
        printf("Longitud de su string = %s is %d\n\n", a[k],length[k]);
    }
    //Ahora hacemos sort del Array//
    //Usaremos un Bubble Sort//
    int n = sizeof(length)/sizeof(length[0]);
    bubbleSort(length, n);
    printf("Array sorteado: \n");
    for (i=0; i < n; i++)
        printf("%d ", length[i]);
    printf("\n");
    printf("%d",length[n-1]);
    //Chequear el mas largo//
    for (i=0; i < 5; ++i)
    {
        if (strlen(a[i]) == length[n-1])
        {
            printf("\nEs el/la linea mas larga %s", a[i]);
        }
        else
        {
            printf("\nNo es el mas largo %s\n", a[i]);
        }

    }
    return 0;
}
