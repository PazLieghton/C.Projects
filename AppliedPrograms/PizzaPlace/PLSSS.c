#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Segmentento Primera Opcion. 1//

//Simplemente enlazada Pide//


typedef struct vector {
    unsigned char vectorchar[100];
    int posicion;
    struct vector* ant, * sig;
} vector;

typedef struct ldoble {
    vector* prim, * ult;
} lista;

void insertar_fifo(lista* l, unsigned char vectorchar, int posicion) {
    vector* nuevoNodo = (vector*)malloc(sizeof(vector));
    nuevoNodo->vectorchar[0] = vectorchar;
    nuevoNodo->posicion = posicion;
    nuevoNodo->ant = NULL;
    nuevoNodo->sig = NULL;

    if (l->prim == NULL) {
        l->prim = nuevoNodo;
        l->ult = nuevoNodo;
    } else {
        nuevoNodo->ant = l->ult;
        l->ult->sig = nuevoNodo;
        l->ult = nuevoNodo;
    }
}


void mostrarLista(lista l) {
    vector* actual = l.prim;

    if (actual == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    printf("\nContenido de la lista:\n");
    while (actual != NULL) {
        printf("Vector: %c, Posición: %d\n", actual->vectorchar[0], (actual->posicion)+1);
        actual = actual->sig;
    }
}

//Funciones Case 2

void mostrarListaASCII(lista l) {
    vector* actual = l.prim;

    if (actual == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    printf("\nContenido de la lista CON MINUSCULAS!:\n");
    while (actual != NULL) {
        if  (actual -> vectorchar[0] >= 97){
            printf("Letra : %c, ASCII: %hhu \n", actual->vectorchar[0], actual -> vectorchar[0]);
        }
        actual = actual->sig;
    }


}



//Fin Case 2//

//Funciones Case 3//

void FIFOcabeza(Vector **cabeza, unsigned char vectorchar) {
    Vector *nuevoVector = crearVector(vectorchar);
    if (*cabeza == NULL) {
        *cabeza = nuevoVector;  // Si la lista está vacía, el nuevo nodo es el primero
    } else {
        Vector *temp = *cabeza;
        while (temp->sig != NULL) {
            temp = temp->sig;  // Avanza hasta el último nodo
        }
        temp->sig = nuevoVector;  // Conecta el nuevo nodo al último
        nuevoVector->ant = temp;
    }
}

void imprimir(vector *cabeza) {
    vector *actual = l;
    int contar_0 = 0, contar_1 = 0;
    while (actual != NULL) {
        printf("%c - ", actual->vectorchar);

        // Imprimir representación binaria de 8 bits
        unsigned char mascara = 0b10000000;
        for (int i = 0; i < 8; i++) {
            printf("%d", (actual->vectorchar & mascara) ? 1 : 0);  // Verifica y muestra cada bit
            if ((actual->vectorchar & mascara))
                contar_1++;  // Incrementa contador de bits 1
            else
                contar_0++;  // Incrementa contador de bits 0
            mascara >>= 1;  // Mueve la máscara de bit hacia la derecha
        }
        printf("\n");

        actual = actual->sig;
    }
    printf("Total de unos: %d\n", contar_1);  // Muestra el total de bits 1
    printf("Total de ceros: %d\n", contar_0);  // Muestra el total de bits 0
}


//Fin Case 3//


//Funcion Destruir//



int main() {
    int num;
    int salida = 0;
    const char *cad = "El triunfo fue PERDER, la derrota fue GANAR.";
    unsigned char *p = (unsigned char*) cad;
    printf("Paz Lieghton Final Agosto 5\n");

    int a;
    a = strlen(cad);
    printf("Longitud de los datos: %d\n", a);

    int i;
    printf("\nEN PRIMERA INSTANCIA ESTOS SON LOS VALORES DEL VECTOR EN unsigned char\n|||||||||||||\n");
    for (i = 0; i < a; i++) {
        printf("%c", p[i]);
    }


    lista l;
    l.prim = NULL;
    l.ult = NULL;

    while (!salida) {
        printf("\n\nMenu:\n");
        printf("1. Guardar los datos de Cad en una lista y luego mostrarla en formato porcentaje c (COMPLETO!)\n");
        printf("2. Guardar en un archivo filtrado.dat las minusculas (COMPLETO!)\n");
        printf("3. \n");
        printf("4. Salir\n");
        printf("Ingrese Numero ");
        scanf("%d", &num);

        switch (num) {
            case 1:
                printf("\n\nElegiste 1.\n");
                if (l.prim == NULL) {
                    printf("\nLa lista esta vacia... creando...\n");
                    for (i = 0; i < a; i++) {
                        insertar_fifo(&l, p[i], i);
                    }
                    mostrarLista(l);
                }
                else{
                    mostrarLista(l); //Si esta llena muestro directamente/
                }
                break;
            case 2:
                printf("\n\nElegiste 2. Estas son las letras y sus ASCII validos \n");

                mostrarListaASCII(l);
                
                if (l.prim == NULL) {
                    printf("La lista generada no existe. Primero debes seleccionar la opción 1 para generarla.\n");
                    break;
                }

                FILE* archivo = fopen("filtrado.dat", "wb");
                if (archivo == NULL) {
                    printf("No se pudo crear el archivo.\n");
                    break;
                    }
                
                printf ("\n\n");
                vector* Sublista = l.prim;

                if (Sublista == NULL) {
                printf("La Sublista minusculas está vacía.\n");
                }

                while (Sublista != NULL) {
                if  (Sublista -> vectorchar[0] >= 97){
                    printf("Guardada: %c ", Sublista->vectorchar[0]);
                    unsigned char vectorchar = Sublista->vectorchar[0];
                    fwrite(&vectorchar, sizeof(unsigned char), 1, archivo);
                }
                Sublista = Sublista->sig;
                }
    
                //fclose(archivo);
                printf("La sublista ha sido guardada en el archivo 'datos.bin'.\n");
                break;

            case 3:
                printf("\n\nElegiste 3.\n");
                printf("Este es el vector en binario: \n");
                mostrarListaASCII(l);
                break;
            case 4:
                printf("\nSaliendo...\n");
                salida = 1;                
                break;
            default:
                printf("\nOPCIÓN INVÁLIDA.\n");
                break;
        }

        printf("\n");
    }
    //Borrado Final//
    printf("\nBORRANDO...\n ... \n ...\n");
    vector* auxiliar = l.prim;
    while (auxiliar != NULL) {
        vector* siguiente = auxiliar->sig;
        free(auxiliar);
        auxiliar = siguiente;
    }

    return 0;
}