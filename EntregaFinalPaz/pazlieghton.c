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
        printf("3. Mostrar los valores de p con 3 bits en 1 como minimo, su cantidad y el porcentaje de bits en 1(Falta el mascara con 3 bits minimo)\n");
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
                printf("Este es el vector en binario: \n");

                vector* actual = l.prim;
                printf("\n\nElegiste 3. Mostrar aquellos Valores que tengan 3 bits en\n");
                int contar_0 = 0, contar_1 = 0;
                while (actual != NULL){
                    unsigned char mascara = 0b10000000;
                    printf(" %c - ", actual->vectorchar[0]);
                    for (i = 0; i < 8;  i++){
                        printf("%d", (actual->vectorchar[0] & mascara) ? 1 : 0);
                        if ((actual->vectorchar[0] & mascara))
                            contar_1++;  // Incrementa contador de bits 1
                        else
                            contar_0++;
                        mascara >>= 1;
                    //Verifica y muestra cada bit
                    }
                    actual = actual -> sig;
                }
                printf ("\nEn el vector hay %d valores de bits en 1, y %d valores de bit en 0", contar_1, contar_0);
                printf("\n\n EL PORCENTAJE DE BITS EN 1 PARA TODO EL VECTOR ES %d PORCIENTO", (contar_1 * 100)/(contar_0+contar_1));
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