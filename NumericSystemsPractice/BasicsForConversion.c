//Decimal unsigned int a hexadecimal
//Unsigned Hex a decimal
//Funcion unsigned char a binario y muestre con 8 caracteres
#include <stdio.h>



int voidtohex(int Base10){
  printf("penis");
  return Base10;
}

int main()
{
  int switcher;
  char output;
  unsigned int number = 100;
  printf("\n1 - To Convert int to hex");
  printf("\n2 - Convert Hex to Int");
  printf("\n3 - Convert Unsigned Char to Binary");
  scanf("\n%d",&switcher);
  switch(switcher){
    case 1:
      printf("\n%d In Binary is",number);
      printf(": %08x",number);
      break;
    case 2:
      break;
    case 3:
      break;
    default:
      printf("\nCLOSING. . .");

  }
  return 0;
  //Test//
}
