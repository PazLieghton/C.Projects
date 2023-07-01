
/*
#include <stdio.h>

void decimalToHex(unsigned char decimal) {
    printf("El valor en hexadecimal es: 0x%02X\n", decimal);
}


int main() {
    unsigned char decimal;
    char continuar;
    
    do {
        printf("Ingrese un valor decimal de 8 bits sin signo: ");
        scanf("%hhu", &decimal);
        
        decimalToHex(decimal);
        
        printf("¿Desea ingresar otro valor? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
    

    return 0;
}


//C program to convert Hexadecimal to Decimal number system

#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char hex[17];
    long long decimal, place;
    int i = 0, val, len;

    decimal = 0;
    place = 1;

    //Input hexadecimal number from user
    printf("Enter any hexadecimal number: ");
    gets(hex);

    //Find the length of total number of hex digit
    len = strlen(hex);
    len--;

    //Iterate over each hex digit

    for(i=0; hex[i]!='\0'; i++)
    {
 
        //Find the decimal representation of hex[i]
        if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i] - 65 + 10;
        }

        decimal += val * pow(16, len);
        len--;
    }

    printf("Hexadecimal number = %s\n", hex);
    printf("Decimal number = %lld", decimal);

    return 0;
}
*/
/*
#include <stdio.h>

void printBinary(unsigned char value);

int main() {
    unsigned char number;
    
    printf("Ingrese un valor entero de 8 bits sin signo: ");
    scanf("%hhu", &number);
    
    printf("El número en binario es: ");
    printBinary(number);
    
    printf("\n");
    
    return 0;
}

void printBinary(unsigned char value) {
    for (int i = 7; i >= 0; i--) {
        unsigned char mask = 1 << i;
        unsigned char bit = (value & mask) ? 1 : 0;
        printf("%d", bit);
    }
}
*/

unsigned int last_n_bits(unsigned int value, int n)
{
    unsigned int mask = -1;
    if (n < sizeof(unsigned) * CHAR_BIT)
        mask = ((1<<n)-1);
    return value & mask;
}
