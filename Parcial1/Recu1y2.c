/*
Paz Sofia Lieghton Pereira
ACLARACIONES PREVIAS:

NO USE NODO RTC, ME MANEJE POSICIONALMENTE, MAS SENCILLO PARA HACER LAS FUNCIONES Y
MENOS CODIGO, tuve problemas convirtiendo a char el archivo, intente lo que intente,
la conversion a binario no funciono y por endo el MSB y LSB no lo pude realizar en
tiempo y forma.

El resto del programa funciona excelente.

PREGUNTAS TEORICAS
EL clock de la pc es el intervalo de procesamiento de la cpu para hacer arimetica,
esta dentro de la CPU, indica el pace para realizar operaciones.

El clock es variable, sirve mucho para nivelar la temperatura de la cpu por si se
sobrecalienta o hay mas techo termico. Al variar el clock, varia la velocidad
de como procesa la cpu o gpu. Si queres que vaya mas rapido, podes overclockearla
manualmente. Con mucho cuidado.

5Ghz son 5 millones de hertz, hertz es frecuencia por segundo. la frecuencia es.
5millones de hertz por segundo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

typedef struct nodo {
  unsigned char dato;
  struct nodo* sig;
}nodo;

/* Inserta al principio */
nodo *insertar_lifo (nodo *l, unsigned char d) {
    nodo *nuevo;

    nuevo = (nodo *) malloc (sizeof (nodo));
    nuevo->dato = d;
    nuevo->sig = l;
    return nuevo;
}

nodo* crea_lista_desde_archivo(nodo* lista) {
    FILE* f;
    int cant = 96, n;
    unsigned char procesador;
    f = fopen("myfile.bin", "rb");
    if (f == NULL) {
        printf("\nError al abrir\n");
        return NULL;
    }
    n = fread(&procesador, sizeof(unsigned int), 1, f);
    while (n == 1 & cant > 14) {
        cant--;
        n = fread(&procesador, sizeof(unsigned int), 1, f);
    }
    while (n == 1){
      lista = insertar_lifo(lista, procesador);
      n = fread(&procesador, sizeof(unsigned int),1,f);
    }

    if (fclose(f) != 0) {
        printf("\nError al cerrar");
        return NULL;
    }
    printf("%d registros leidos desde archivo\n", cant);

    return lista;
}

void mostrarHex (nodo *l) {
    int i;
    printf ("Lista en Hexa");
    for(i = 0; i < 14; ++i){
        printf (" --> 0x%02X", l->dato);
        l = l->sig;
    }
    printf ("\n");
}

void mostrar (nodo *l) {
    int i;
    printf ("Lista en Decimal");
    for(i = 0; i < 14; ++i){
        printf (" --> %d", (l->dato));
        l = l->sig;
    }
    printf ("\n");
}

/*void Hexabin(char* nodo)
{

    int i = 0;

    while (nodo[i]) {
        switch (nodo[i]) {
        case '0':
            printf("0000");
            break;
        case '1':
            printf("0001");
            break;
        case '2':
            printf("0010");
            break;
        case '3':
            printf("0011");
            break;
        case '4':
            printf("0100");
            break;
        case '5':
            printf("0101");
            break;
        case '6':
            printf("0110");
            break;
        case '7':
            printf("0111");
            break;
        case '8':
            printf("1000");
            break;
        case '9':
            printf("1001");
            break;
        case 'A':
        case 'a':
            printf("1010");
            break;
        case 'B':
        case 'b':
            printf("1011");
            break;
        case 'C':
        case 'c':
            printf("1100");
            break;
        case 'D':
        case 'd':
            printf("1101");
            break;
        case 'E':
        case 'e':
            printf("1110");
            break;
        case 'F':
        case 'f':
            printf("1111");
            break;
        }
        i++;
    }
}*/

void alarmaactual(nodo *l){
  int i;
  printf("Alarma actual: ");
  l = l->sig;
  printf("Segundos Alarma %d  ", l->dato);
  l = l->sig;
  l = l->sig;
  printf("Minutos Alarma %d  ", l->dato);
  l = l->sig;
  l = l->sig;
  printf("Horas Alarma %d  ", l->dato);
  printf ("\n");
}

nodo* alarmaactualizada(nodo *l,int seg,int min, int hor){
  int i;
  printf("\nAlarma ACTUALIZADA: ");
  l = l->sig;
  printf("Segundos Alarma %d  ", l->dato = seg);
  l = l->sig;
  l = l->sig;
  printf("Minutos Alarma %d  ", l->dato = min);
  l = l->sig;
  l = l->sig;
  printf("Horas Alarma %d  ", l->dato = hor);
  printf ("\n");
  return l;
}

int main()
{
    nodo* lista = NULL;
    FILE *arch;
    int n = 1, i = 0, op, seg=61,min=61,hor=25;
    lista = crea_lista_desde_archivo(lista);
    printf("Elija una opcion: \n");
    printf("1-Mostrar Valores \n");
    printf("2-Programar Alarma \n");
    printf("3-MSB y LSB \n");
    printf("4-Salir \n");
    scanf("%d", &op);
    while(op != 4)
    {
        switch(op)
        {
            case 1:
                    mostrar(lista);
                    mostrarHex(lista);
                    printf("\n");
                    /*Hexabin(lista);*/
                    break;
            case 2:
                    alarmaactual(lista);
                    while (seg > 60){
                    printf("\nIngrese segundos de alarma: ");
                    scanf("%d",&seg);
                    }
                    while (min > 60){
                    printf("\nIngrese minutos de alarma: ");
                    scanf("%d",&min);
                    }
                    while (hor > 23){
                      printf("\nIngrese horas de alarma: ");
                      scanf("%d",&hor);
                    }
                    alarmaactualizada(lista,seg,min,hor);
                    break;
            case 3:
                    /*No me dio el tiempo PARA MSV Y LSB*/
                    break;
            case 4:
                    free(lista);
                    exit(0);
            default:    printf("Por favor, elija una opcion valida. \n");
                        break;
        }
        printf("Elija una opcion: \n");
        printf("1-Mostrar Valores \n");
        printf("2-Programar Alarma \n");
        printf("3-MSB y LSB \n");
        printf("4-Salir \n");
        scanf("%d", &op);
    }
    return 0;
}
