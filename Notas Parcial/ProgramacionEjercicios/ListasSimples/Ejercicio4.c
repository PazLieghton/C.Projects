#include <stdio.h>
#include <stdlib.h>

/*Declaración de la estructura para los nodos (tipo de datos)*/
typedef struct nodo {
    int dato;
    struct nodo *sig;
} nodo;

/*Inserta al final*/
/*l es un puntero el primer nodo de la lista, d es el dato a insertar*/
nodo *insertar_fifo (nodo *l, int d){
    nodo *nuevo, *p;

    nuevo = (nodo*) malloc (sizeof (nodo));
    nuevo->dato = d;
    nuevo->sig = NULL; /*Porque va a ser el ultimo nodo*/
    if (l == NULL)
        return nuevo;
    /*Como la lista no esta vacia la recorro buscando el ultimo nodo*/
    p = l;
    while (p->sig != NULL)
        p = p->sig;
    /*Ahora p es el ultimo nodo*/
    p->sig = nuevo;
    return l;
}

/*Muestra los elementos de la lista*/
void mostrar (nodo *l) {
    printf ("Lista");
    while (l != NULL) {
        printf (" --> %d", l->dato);
        l = l->sig;
    }
    printf ("\n");
}

/*Libera toda la memoria ocupada por la lista*/
nodo *destruir (nodo *l) {
    nodo * aux;

    while (l != NULL) {
        aux = l;
        l = l->sig;
        free (aux);
    }
    printf ("lista destruida\n");
    return NULL;
}

/*Pide entros hasta que se ingrese cero y los inserta en la lista*/
nodo *ingresa_usuario(nodo *lista) {
    int temp;

    printf ("Ingrese un nro entero (cero finaliza):");
    scanf ("%d", &temp);
    while (temp != 0) {
        lista = insertar_fifo (lista, temp);
        printf ("\nIngrese otro nro entero (cero finaliza):");
        scanf ("%d", &temp);
    }
    return lista;
}

/*Programa principal que hace uso de las funciones definidas arriba*/
/*Implementa la separacion pedida en el enunciado*/
int main ()
    {
    nodo *lista = NULL; /*Lista general*/
    nodo *imp = NULL; /*Lista de impares*/
    nodo *par = NULL; /*Lista de pares*/
    nodo *p; /*Puntero para recorrer la lista general*/

    /*Inserta en la lista general los valores que ingrese el usuario*/
    lista = ingresa_usuario (lista);
    mostrar (lista);

    /*Recorre la lista general y copia los elementos en una de las dos listas */
    /*segun si son pares o impares*/
    p = lista;
    while (p != NULL) { /*Mientra no llega al final*/
        if (p->dato % 2 == 0) /*Si el dato es par*/
            par = insertar_fifo (par, p->dato); /*Inserta en la lista de pares*/
        else /*El dato es impar*/
            imp = insertar_fifo (imp, p->dato); /*Inserta en la lista de impares*/
        p = p->sig;
    }

    /*Destruir lista original*/
    lista = destruir(lista);

    /*Muestro listas pares e impares*/
    printf ("Lista de pares:\n");
    mostrar (par);
    printf ("Lista de impares:\n");
    mostrar (imp);

    /*Destruir las listar restantes antes de terminar el programa*/
    par = destruir(par);
    imp = destruir(imp);

    return 0;
    }
