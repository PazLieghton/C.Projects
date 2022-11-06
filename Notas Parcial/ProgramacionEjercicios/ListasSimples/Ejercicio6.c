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

/*Funcion que implementa lo pedido en el enunciado*/
/*Busca un elelemento en la lista, mostrando tambien el anterior en caso de existir*/
/*Si se repitiera el elemento solo se considera la primera ocurrencia*/
/*l es un puntero el primer nodo de la lista, d es el dato a buscar*/
void buscar (nodo *l, int d) {
    if (l == NULL) {
        printf ("La lista esta vacia");
        return;
    }
    /*Lista no vacia*/
    if (l->dato == d) {
        printf ("Elemento encontrado: %d. Es el primero de la lista\n", l->dato);
        return;
    }
    /*No es el primero de la lista*/
    while (l->sig != NULL && l->sig->dato != d)
        l = l->sig;
    if (l->sig != NULL) /*l->sig->dato es el buscado*/
        printf ("Elemento encontrado: %d. Anterior: %d\n", l->sig->dato, l->dato);
    else
        printf ("Elemento %d no encontrado\n", d);
}

/*Programa principal que hace uso de las funciones definidas arriba*/
int main () {
    nodo *lista = NULL; /*comienzo de la lista*/
    int x;

    /*Inserta en la lista los valores que ingrese el usuario*/
    lista = ingresa_usuario (lista);
    mostrar (lista);

    /*Busqueda pedida en el enunciado*/
    printf ("Ingrese un valor a buscar:");
    scanf ("%d", &x);
    buscar (lista, x);

    /*Destruir lista (liberar memoria)*/
    lista = destruir(lista);

    return 0;
    }
