//P1 - Strings - EJ3//

#include <stdio.h>
#include <string.h>

//Leer 5strings por teclado y mostrar el “mayor”(LEXICOGRAFICAMENTE)//
int main() {
    int i, j;
    char str[7][100], temp [100];

    printf("\n Ingrese 5 palabras: ");
    for(i = 0; i < 4; ++i)
        scanf("%s [^\n]",str[i]);

    for(i = 0; i < 4; ++i)
        for(j=i+1; j <= 5 ; ++j)
        {
            if(strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],temp);
            }
        }
    printf("\nEn orden lexicografico: \n");
        for(i = 0; i < 6; ++i)
        {
            puts(str[i]);
        }
    return 0;
}
