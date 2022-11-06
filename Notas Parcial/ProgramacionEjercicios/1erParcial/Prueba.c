//Parcial 1 de Programaciom//
//Paz Lieghton Ing. ELectronica//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pizzas
{
    char nombrepizza[20];
    float precio;
}p;//Hago Typedef p//

//Creo mis dos Nodos//
typedef struct nodolistapizzas{
  char nodonombrepizza[20];
  float nodoprecio;
  struct nodolistapizzas *sig;
}listapizzas;

typedef struct nodolistapedidos{
  int numpedido;
  int numcombo;
  int cantidad;
  float totalpagar;
  struct nodolistapedidos *sig;
}listapedidos;
//Fin Dos nodos//

//Fifo Lista Pizzas//
listapizzas *fifo(listapizzas *lista, float precio,char productos[20]){
    listapizzas *nuevo, *p;
    int i;

    nuevo = ((listapizzas*) malloc (sizeof (listapizzas)));
    strcpy(nuevo -> nodonombrepizza, productos);
    nuevo->nodoprecio = precio;
    nuevo->sig = NULL;
    if (lista == NULL)
        return nuevo;
    p = lista;
    while (p->sig != NULL)
        p = p->sig;
    p->sig = nuevo;
    return lista;
}
//Fin Fifo//

//Fifo pedidos//

listapedidos *fifopedidos(listapedidos *lista, int pedido,int numcombo,int cantidad){
    listapedidos *nuevo, *p;
    int i;
    nuevo = ((listapedidos*) malloc (sizeof (listapedidos)));
    nuevo -> numpedido = pedido;
    nuevo -> numcombo = numcombo;
    nuevo -> cantidad = cantidad;
    nuevo -> totalpagar = /*funcionimportante(numcombo)*/ 1;
    nuevo->sig = NULL;
    if (lista == NULL)
        return nuevo;
    p = lista;
    while (p->sig != NULL)
        p = p->sig;
    p->sig = nuevo;
    return lista;
}

//Fin fifo pedidos//

//funcionimportante debe hallar el valor de float de la lista enlazada de los precios//
//void (funcionimportante){
//  return 1;
//}



//Inicio Crear lista desde Archivo//
listapizzas *lista_desde_archivo(listapizzas *lista){
  FILE *f;
  int cant = 0, n,m;
  char productos[20];
  float precio;
  f = fopen ("precioproductos.dat","rb");
  if (f == NULL){
    printf("\n Error al abrir");
    return NULL;
  }
  n = fread (&productos, sizeof(char),20,f);
  n = fread (&precio, sizeof(float),1,f);
  while (n == 1){
    cant ++;
    lista = fifo(lista,precio,productos);
    n = fread (&productos, sizeof(char),20,f);
    n = fread (&precio, sizeof (float),1,f);
  }
  if (fclose(f) != 0){
    printf("\n Error cerrando");
    return NULL;
  }
  return lista;
}



//Mostrar la lista//
void mostrar_lista(listapizzas *lista){
	printf("Contenido de la lista:\n");
	while (lista != NULL){
		printf("Nombre %s, Precio %f\n",lista->nodonombrepizza ,lista->nodoprecio);
		lista=lista->sig;
	}
	return;
}
//Fin mostrar lista//



int main(){
  //Mis recursos//
  int num, i;
  char nombreingreso[20];
  float precioingreso;
  int existearchivo = 0;
  //Segmento de Carga de Archivo//
  FILE *f;
  f = fopen ("precioproductos.dat","rb");
  if (f == NULL){
    fprintf(stderr, "|||||||||||\nADVERTENCIA Archivo precioproductos vacio o lleno NO EXISTE\n|||||||||||\n");
    existearchivo = 1;
  }
  //Creo Un nodo desde el archivo//

  listapizzas *lista = NULL;
  printf("SISTEMA DE PROCESAMIENTO DE PIZZAS VERSION - 2000\n");



  printf("\n\nFavor Ingresar la operacion deseada:\n");
  printf("1 - Cargar sus pedidos");
  printf("\n2 - Mostrar lista de productos y pedidos\n");
  printf("3 - Cambiar precio de pizza y recalcular pedidos");
  printf("\n0 - Para cerrar el programa\n");

  //Cuerpo de Programa van a ser solo switch statements//
  num = 4;
  while (num != 0){
      if (num == 1) {
        printf("Usted Selecciono Operacion 1\n");
        printf("Cargar sus pedidos\n");
        printf("Sin finalizar\n");
      }
      if (num == 2){
        printf("Usted Selecciono Operacion 2\n");
        if (existearchivo == 0){
          lista = lista_desde_archivo(lista);
          mostrar_lista(lista);
        }
        else{
          printf("No existe archivo no se puede realizar esta operacion, favor usar operacion 1\n");
          exit(0);
        }
      }
      if (num == 3) {
        printf("Usted Selecciono Operacion 1\n");
        printf("Cambiar el precio de pizzas y sus pedidos\n");
        printf("Sin finalizar\n");
      }
      scanf("%d",&num);
    }
  printf("Usted Selecciono Operacion 0\n");
  printf("CERRANDO PROGRAMA\n");
  exit(0);
  free(lista);
  return 0;
}
