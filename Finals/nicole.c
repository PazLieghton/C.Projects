#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//
/*Parta de la linea unsigned char *r = (unsigned char*) "BOB TIENE UN RADAR QUE PUEDE RECONOCER UN OSO EN EL BOSQUE";
menu repetitivo
1 guardar en una doblemente enlazada y luego imprimir en %c y binario de 8 bits.
//si la opcion ya fue ejecutada destruir la lista existente.

2 suponga que los primeros 64 valores del vector son los rtc
r[0]= registro 00
imprimir A B y C en binario e indique
UIP(esta activo?
PIE & AIE( estan ambos activos?)
PF o AF (alguno activo?)

3 fin

*/

typedef struct nodo {
  char dato;
  struct nodo *sig;
  struct nodo *prev;
} nodo;

typedef struct listadoble {
  nodo *top, *bot;
} lista;

void  borrar(lista);
void  imprimirlista(lista);
lista InsertFinal(lista, char a);
void  imprimirABC(lista);
void  RevisarRegistros(lista);
void  binario(char a);

int main()
{
    char *datos = "BOB TIENE UN RADAR QUE PUEDE RECONOCER UN OSO EN EL BOSQUE";
    unsigned char *r = (unsigned char*) datos;


    lista Caracteres;
    Caracteres.top = NULL;
    Caracteres.bot = NULL;
    int i = 0, A=0;
    int choice;
    do {
        printf("\nMENU:\n");
        printf("1_guardar en lista y luego imprimir en %c y binario de 8 bits\n");
        printf("2_imprimir A B y C en binario e indique el estado de: UIP, (PIE & AIE), (PF Ã³ AF )\n");
        printf("3_ Salir \n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            borrar(Caracteres);Caracteres.top = NULL;Caracteres.bot = NULL;//se que es reiterativo pero funciona
            i = 0;
            while (r[i] != 0) {
            //agrego los datos a al final de la lista
            Caracteres = InsertFinal(Caracteres, r[i]);
            i++;
            }
            imprimirlista(Caracteres);
            break;
        case 2:
            if (Caracteres.top != NULL){
                //imprimo A B y C --> r[10], r[11] y r[12] respectivamente.
                imprimirABC(Caracteres);
                RevisarRegistros(Caracteres);
            }


            break;
        default:
            break;
            }

    } while (choice != 3);

    borrar (Caracteres);
    return 0;
}
//FUNCIONES:
void borrar(lista l) {
  nodo *aux, *ptr;
  ptr = l.top;
  int i = 0;
  while (ptr != NULL) {
    //printf("\nFunc.BORRAR-> %d: %d", i + 1, ptr->dato);
    aux = ptr;
    ptr = ptr->sig;
    free(aux);
    i++;
  }
  l.top = NULL;
  l.bot = NULL;
  printf("\nLista existente borrada exiosamente");

  return;
}
void  binario(char a){
int k=1, auxiliar=0, bin =0;
      while (a != 0) {
         auxiliar =  a % 2;
          a /= 2;
         bin += auxiliar * k;
         k *= 10;
      }
    printf("%d\n", bin);
k=1;bin=0;auxiliar=0;
return;
}
void imprimirlista(lista car) {
  int i = 0;
  nodo *aux;
  aux = car.top;
  printf("\ndato  caracter   hexa   binario\n");
  while (aux != NULL) {
    printf("dato:%d\t %c\t %x\t ", i ,aux->dato ,aux->dato);//Caracter: %c| Hexa: 0x%hhx  |  Decimal: %d\n
    binario(aux->dato);
    i++;
    aux = aux->sig;
  }
  return;
}
lista InsertFinal(lista car, char a)  {
  nodo *nuevo;
  nuevo = (nodo *)malloc(sizeof(nodo));
  nuevo->dato = a;
  nuevo->sig = NULL;
  nuevo->prev = car.bot;

  if (car.top == NULL)
    car.top = nuevo;
  else
    car.bot->sig = nuevo;

  car.bot = nuevo;
  return car;
}
void  imprimirABC(lista car){
  int i = 0, k=1, auxiliar=0, bin =0;
  nodo *aux;
  aux = car.top;
  printf("\ndato  caracter   hexa   binario\n");
  while (aux != NULL) {
        if (i == 10 || i == 11 || i == 12){
        printf("dato:%x\t %c\t %x\t ", i ,aux->dato ,aux->dato);//Caracter: %c| Hexa: 0x%hhx  |  Decimal: %d\n
         binario(aux->dato);
        }
    i++;
    aux = aux->sig;
  }
  return;
}
void  RevisarRegistros(lista car){
      int i = 0, A=0;
  nodo *aux;
  aux = car.top;
  printf("\nReviso estado de los bits UIP, PIE, AIE, PF y AF: \n");
  while (aux != NULL){
    if (i==10){ if ((aux->dato & 0x80)!=0) printf("\nUIP activo");
                else printf("\nUIP inactivo");}//mascara para ver si hay un uno en 10000000

    if (i==11){ if ((aux->dato & 0x40)!=0 && (aux->dato & 0x20)!=0) printf("\nEl grupo PIE y AIE se encuentran ambos activos");
                else printf("\nEl grupo PIE y AIE NO se encuentran ambos activos");}//mascara para ver si hay unos en 01100000

    if (i==12){ if ((aux->dato & 0x40)!=0) printf("\nPF activo");
                else printf("\nPF inactivo");
                if (((aux->dato & 0x20) != 0)) printf("\nAF activo\n");
                else printf("\nAF inactivo\n");}//mascara para ver si hay un uno 01000000 o en 00100000
    i++;
    aux = aux->sig;
  }
  return;
}