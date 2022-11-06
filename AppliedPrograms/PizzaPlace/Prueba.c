#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nombre [20];
    float precio;
} producto;

typedef struct nodo{
    int numpedido;
    int numcombo; //1 al 10 dentificará los distintos tipos de pizzas.
    int cantidad;
    float totalapagar;
    struct nodo *sig;
} nodo;


void cargar_precios(producto productos [])
{
    FILE *f;
    int n;

    f = fopen ("precioproductos.dat", "rb");
    if (f == NULL) {
        printf ("Error al abrir el archivo de precios\n");
        return;
    }
    n = fread (productos, sizeof (productos [0]), 10, f);
    if (n != 10) {
        printf ("Error: se leyeron menos de 10 precios\n");
        fclose (f);
        return;
    }
    if (fclose (f) != 0) {
        printf ("Error al cerrar el archivo de precios\n");
        return;
        }
    printf ("Archivo de precios cargado ok\n");
}


nodo *insertar_fifo (nodo *l, nodo *nuevo)
{
    nodo *p;
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
    } //cierra else
}


nodo *ingresar_pedido (nodo *l, producto productos [])
{
    nodo *nuevo;

    nuevo = (nodo *) malloc (sizeof(nodo));

    printf ("Ingrese numpedido: ");
    scanf ("%d", &nuevo->numpedido);

    printf ("Ingrese numcombo: ");
    scanf ("%d", &nuevo->numcombo);

    printf ("Ingrese cantidad: ");
    scanf ("%d", &nuevo->cantidad);

    nuevo->totalapagar = productos [nuevo->numcombo - 1].precio * nuevo->cantidad;

    return insertar_fifo (l, nuevo);
}


void mostrar_precios(producto productos [])
{
    int i;

    printf ("PRECIOS\nCombo       Precio\n");
    for (i=0; i < 10; i++)
        printf ("%-11s $%7.2f\n", productos [i].nombre, productos [i].precio);
}


void mostrar_pedidos(nodo *l)
{
    printf ("PEDIDOS\nnumpedido numcombo cantidad totalapagar\n");

    while (l != NULL) {
        printf ("%9d %8d %8d %10.2f\n", l->numpedido, l->numcombo, l->cantidad, l->totalapagar);
        l = l->sig;
    }
}


void actualizar_precio (producto productos [])
{
    int i;
    char nombre[10];
    float precio;

    printf ("Ingrese el nombre a buscar: ");
    scanf ("%s", nombre);

    for (i=0; i < 10; i++) {
        if (strcmp (nombre, productos[i].nombre) == 0) {
            printf ("Encontrado. Ingrese el nuevo precio: ");
            scanf ("%f", &productos[i].precio);
            return;
        }
    }
    printf ("Nombre no encontrado");
}


void recalcular (nodo *l, producto productos[])
{
    while (l != NULL) {
        l->totalapagar = productos[l->numcombo - 1].precio * l->cantidad;
        l = l->sig;
    }
}


nodo *destruir (nodo *l)
{
    nodo *aux;

    while (l != NULL) {
        aux = l->sig;
        free (l);
        l = aux;
    }
}


int main ()
{
    producto productos [10];
    int op;
    nodo *pedidos = NULL;

    do {
        printf ("\n1.Cargar archivo\n2.Ingresar pedido\n3.Mostrar\n4.Actualizar precio\n");
        printf ("5.Recalcular\n6.Salir\nIngrese opcion: ");
        scanf ("%d", &op);
        switch (op) {
            case 1:
                cargar_precios (productos);
                break;
            case 2:
                pedidos = ingresar_pedido (pedidos, productos);
                break;
            case 3:
                mostrar_precios (productos);
                mostrar_pedidos (pedidos);
                break;
            case 4:
                actualizar_precio(productos);
                break;
            case 5:
                recalcular (pedidos, productos);
                break;
            case 6: //salir
                break;
            default:
                printf ("Opcion invalida\n");
        }
    } while (op != 6);

    pedidos = destruir (pedidos);
    return 0;
}
