/*
Parcial 1 Mayo 20 VEASE EJ 1ab LISTAS DOBLES
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Para hallar la longitud del string


typedef struct nodo_d {
    char nombre[100];
    int edad;/*Char y int para el dato de users*/
    struct nodo_d *ant, *sig;
} nodo_d;

/* La lista doble esta representada por una estructura con 2 punteros: primero y ultimo */
typedef struct ldoble {
    nodo_d *prim, *ult;
} lista;

//Parte 1//

void insertar_fifo(lista* l, const char* nombre, int edad) {
    // Crear un nuevo nodo
    nodo_d* nuevoNodo = (nodo_d*)malloc(sizeof(nodo_d));
    strcpy(nuevoNodo->nombre, nombre); // Usar strcpy para copiar el nombre
    nuevoNodo->edad = edad;
    nuevoNodo->ant = NULL;
    nuevoNodo->sig = NULL;

    if (l->prim == NULL) {
        // La lista está vacía, el nuevo nodo será el primero y el último
        l->prim = nuevoNodo;
        l->ult = nuevoNodo;
    } else {
        // Agregar el nuevo nodo al final de la lista
        nuevoNodo->ant = l->ult;
        l->ult->sig = nuevoNodo;
        l->ult = nuevoNodo;
    }
}



void mostrarLista(lista l) {
    nodo_d* actual = l.prim;

    if (actual == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    printf("Contenido de la lista:\n");
    while (actual != NULL) {
        printf("Nombre: %s, Edad: %d\n", actual->nombre, actual->edad); // Imprimir el nombre como cadena de caracteres
        actual = actual->sig;
    }
}

//Parte 2//



int main() {
    int num,i;
    char nombre[100];
    int salida = 0;
    int d = 1;

    while (!salida) {
        printf("\n\nMenu:\n");
        printf("1. Inserta nombre y edad de clientes (Edad 0, finaliza, el input)\n");
        printf("2. Dada la lista de clientes generar una lista con mayores a un umbral X\n");
        printf("3. \n");
        printf("4. \n");
        printf("5. Exit\n");
        printf("Ingrese Numero ");
        scanf("%d", &num);
        
        lista l;
        l.prim = NULL;
        l.ult = NULL;

        switch (num) {
            case 1:
                printf("Elegiste 1.(0, para terminar)\n");
                while (d != 0) {
                    printf("\nIngrese los datos (0 para terminar): ");
                    printf("\nInserte la edad: ");
                    scanf("%d", &d);
                    if (d == 0){
                        break;
                        mostrarLista(l);
                    }
                    printf("\nInserte el nombre: ");
                    getchar();
                    fgets(nombre, sizeof(nombre), stdin);
                    nombre[strcspn(nombre, "\n")] = '\0';
                    insertar_fifo(&l, nombre, d);
                }
                mostrarLista(l);
                break;
            case 2:
                printf("\n\nElegiste 2.\n");
                break;
            case 3:
                printf("\n\nElegiste 3.\n");
                break;
            case 4:
                printf("\n\nElegiste 4.\n");
                break;
            case 5:
                printf("Saliendo...\n");
                salida = 1;
                break;
            default:
                printf("INVALIDA OPCION.\n");
                break;
        }
        
        printf("\n");
    }
    
    return 0;
}
