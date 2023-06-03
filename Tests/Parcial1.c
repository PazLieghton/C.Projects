/**/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct {
    char name[MAX];
    int age;
}cliente;


typedef struct nodo1{
    char nombre[20];
    int edad;
    struct nodo1 *sig;
} nodo1;

/**/


typedef struct nodo2{
    char nombremay[20];
    int edadmay;
    struct nodo2 *sig;
} nodo2;

//SEGMENTO 1//
nodo1 *insertar_fifo (nodo1 *l, nodo1 *nuevo)
{
    nodo1 *p;
    
    nuevo->sig = NULL;
    if (l == NULL)
        return nuevo;
    else
    {
        p = l;
        while (p->sig != NULL)
            p = p->sig;
        p->sig = nuevo;
        return l;
    }
}


nodo1 *ingresar_lista (nodo1 *l, cliente clientes [], int agge)
{

    nodo1 *nuevo;
    nuevo = (nodo1 *) malloc (sizeof(nodo1));
    nuevo -> edad = agge;
    printf ("Ingrese Nombre: ");
    scanf ("%s", nuevo->nombre);
    return insertar_fifo (l, nuevo);
}


void mostrar_lista(nodo1 *l)
{
    printf ("\n\nNOMBRE --------------------- EDAD\n");

    while (l != NULL) {
        printf ("%s - - - - - - - %d \n", l->nombre, l->edad);
        l = l->sig;
    }
}

/*Este segmento lo usare para el punto 2*/
nodo2 *insertar_fifo2 (nodo2 *l, nodo2 *nuevo)
{
    nodo2 *p;
    
    nuevo->sig = NULL;
    if (l == NULL)
        return nuevo;
    else
    {
        p = l;
        while (p->sig != NULL)
            p = p->sig;
        p->sig = nuevo;
        return l;
    }
}


nodo2 *ingresar_viejos (nodo1 *p, nodo2 *l, cliente clientes [],int lim)
{
    nodo2 *nuevo;
    nodo1 *nuevo2;

    nuevo = (nodo2 *) malloc (sizeof(nodo2));
    while (p != NULL){
    	if (p->edad > lim){
    		l ->edadmay = p->edad;
    		strcpy(l->nombremay , p-> nombre);
    }

    return insertar_fifo2 (l, nuevo);
}
}


void mostrar_viejos(nodo2 *l)
{
    printf ("\n\nNOMBRE --------------------- EDAD\n");

    while (l != NULL) {
        printf ("%s - - - - - - - %d \n", l->nombremay, l->edadmay);
        l = l->sig;
    }
}



nodo1 *destruir1 (nodo1 *l)
{
    nodo1 *aux;
    
    while (l != NULL) {
        aux = l->sig;
        free (l);
        l = aux;
    }
}

nodo2 *destruir2 (nodo2 *l)
{
    nodo2 *aux;
    
    while (l != NULL) {
        aux = l->sig;
        free (l);
        l = aux;
    }
}

int main(){
	cliente clientes[MAX];
	int op, i;
	int agge  = 1;
	nodo1 *listaclientes = NULL;
	nodo2 *listaviejos = NULL;


	do{
	printf("\n1. Insertar nombre y edad de un cliente Individual + MOSTRAR lista \n2.Lista Mayores \n3. NO ME DIO TIEMPO (Sin embargo, usare este punto para mostrar lista)\n4.NO ME DIO TIEMPO PARA SUBIR A ARCHIVO \n");
	printf("5. Salir\nIngrese opcion:  ");
	scanf ("%d", &op);
	switch(op){
    	case 1:
    		printf("Usted eligio opcion 1\n");
    		printf ("Inserte clientes 0 TERMINA ESTA OPERACION:  \n\n\n");
    		printf("\n\nIngrese edad del cliente: ");
    		scanf ("%d", &agge);
    		if (agge == 0){
    			printf("ERROR, NO PUEDEN HABER EDADES DE 0 ANIOS, vuelva a ingresar");
    			break;
    		}
    	    listaclientes = ingresar_lista (listaclientes, clientes, agge);
    		mostrar_lista(listaclientes);
    		break;
    	case 2:
    		destruir2(listaviejos);
    		printf("Usted eligio opcion 2\n");

    		printf("\nIngrese la edad mayor a:  ");

    		printf("\nLa lista de mayores es: \n");
    		listaviejos = ingresar_viejos(listaclientes, listaviejos,clientes,20);
    		mostrar_viejos(listaviejos);

  			break;
        case 3:
        	printf("Usted eligio opcion 3\n");
        	mostrar_lista(listaclientes);
        	break;
		case 4:
			printf("Usted eligio opcion 4\n");
			break;
        case 5:
        	printf("Usted eligio opcion 5\n");
        	destruir1(listaclientes);
			break;
        default:
            printf ("OPCION INVALIDA\n");
        }

	}while (op != 5);

	return 0;
}