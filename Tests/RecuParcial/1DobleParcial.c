#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo_d {
    char nombre[100];
    int edad;
    struct nodo_d* ant, * sig;
} nodo_d;

typedef struct ldoble {
    nodo_d* prim, * ult;
} lista;

void insertar_fifo(lista* l, const char* nombre, int edad) {
    nodo_d* nuevoNodo = (nodo_d*)malloc(sizeof(nodo_d));
    strcpy(nuevoNodo->nombre, nombre);
    nuevoNodo->edad = edad;
    nuevoNodo->ant = NULL;
    nuevoNodo->sig = NULL;

    if (l->prim == NULL) {
        l->prim = nuevoNodo;
        l->ult = nuevoNodo;
    }
    else {
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

    printf("\nContenido de la lista:\n");
    while (actual != NULL) {
        printf("Nombre: %s, Edad: %d\n", actual->nombre, actual->edad);
        actual = actual->sig;
    }
}

void generarSublista(lista* original, lista* sublista, int umbralEdad) {
    nodo_d* actual = original->prim;

    while (actual != NULL) {
        if (actual->edad >= umbralEdad) {
            insertar_fifo(sublista, actual->nombre, actual->edad);
        }
        actual = actual->sig;
    }
}

void ordenarListaEdad(lista* l) {
    int intercambio = 1;
    nodo_d* actual = l->prim;
    while (intercambio) {
        intercambio = 0;
        while (actual->sig != NULL) {
            if (actual->edad > actual->sig->edad) {
                // Intercambiar nodos
                nodo_d* temp = actual->sig;
                actual->sig = temp->sig;
                temp->sig = actual;
                temp->ant = actual->ant;
                actual->ant = temp;
                if (temp->ant != NULL) {
                    temp->ant->sig = temp;
                }
                if (actual->sig != NULL) {
                    actual->sig->ant = actual;
                }
                if (l->prim == actual) {
                    l->prim = temp;
                }
                intercambio = 1;
            }
            else {
                actual = actual->sig;
            }
        }
        actual = l->prim;
    }
}

void eliminarNodo(lista* l, const char* nombre) {
    nodo_d* actual = l->prim;

    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            if (actual->ant != NULL) {
                actual->ant->sig = actual->sig;
            }
            else {
                l->prim = actual->sig;
            }
            if (actual->sig != NULL) {
                actual->sig->ant = actual->ant;
            }
            if (actual == l->ult) {
                l->ult = actual->ant;
            }
            free(actual);
            printf("El cliente con el nombre '%s' ha sido eliminado de la lista.\n", nombre);
            return;
        }
        actual = actual->sig;
    }

    printf("El cliente con el nombre '%s' no fue encontrado en la lista.\n", nombre);
}

int main() {
    int num, i;
    char nombre[100];
    int salida = 0;
    int d = 1;

    lista l;
    l.prim = NULL;
    l.ult = NULL;

    lista sublista;
    sublista.prim = NULL;
    sublista.ult = NULL;

    while (!salida) {
        printf("\nMenu:\n");
        printf("1. Insertar nombre y edad de clientes (Edad 0 para finalizar)\n");
        printf("2. Generar una sublista con clientes mayores a un umbral de edad\n");
        printf("3. Buscar cliente por nombre\n");
        printf("4. Guardar sublista en un archivo binario\n");
        printf("5. Salir\n");
        printf("Ingrese un número: ");
        scanf("%d", &num);

        switch (num) {
            case 1:
                printf("Seleccionaste 1. (Edad 0 para finalizar)\n");
                while (d != 0) {
                    printf("\nIngrese los datos (0 para finalizar): \n");
                    printf("Inserte la edad: ");
                    scanf("%d", &d);
                    if (d == 0) {
                        break;
                    }
                    printf("Inserte el nombre: ");
                    getchar();
                    fgets(nombre, sizeof(nombre), stdin);
                    nombre[strcspn(nombre, "\n")] = '\0';
                    insertar_fifo(&l, nombre, d);
                }
                mostrarLista(l);
                break;

            case 2:
                printf("Seleccionaste 2.\n");
                if (sublista.prim != NULL) {
                    nodo_d* actual = sublista.prim;
                    while (actual != NULL) {
                        nodo_d* siguiente = actual->sig;
                        free(actual);
                        actual = siguiente;
                    }
                    sublista.prim = NULL;
                    sublista.ult = NULL;
                }
                int umbralEdad;
                printf("Ingrese el umbral de edad: ");
                scanf("%d", &umbralEdad);
                generarSublista(&l, &sublista, umbralEdad);
                mostrarLista(sublista);
                break;

            case 3:
                printf("Seleccionaste 3.\n");
                if (l.prim == NULL) {
                    printf("La lista está vacía.\n");
                    break;
                }
                char nombreBuscado[100];
                printf("Ingrese el nombre a buscar: ");
                getchar();
                fgets(nombreBuscado, sizeof(nombreBuscado), stdin);
                nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';
                nodo_d* actual = l.prim;
                nodo_d* previo = NULL;
                nodo_d* siguiente = NULL;
                int encontrado = 0;

                while (actual != NULL) {
                    if (strcmp(actual->nombre, nombreBuscado) == 0) {
                        encontrado = 1;
                        break;
                    }
                    previo = actual;
                    actual = actual->sig;
                }

                if (encontrado) {
                    if (previo != NULL) {
                        printf("Cliente previo:\n");
                        printf("Nombre: %s, Edad: %d\n", previo->nombre, previo->edad);
                    }
                    printf("Cliente encontrado:\n");
                    printf("Nombre: %s, Edad: %d\n", actual->nombre, actual->edad);
                    siguiente = actual->sig;
                    if (siguiente != NULL) {
                        printf("Cliente siguiente:\n");
                        printf("Nombre: %s, Edad: %d\n", siguiente->nombre, siguiente->edad);
                    }
                }
                else {
                    printf("El cliente con el nombre '%s' no fue encontrado.\n", nombreBuscado);
                }
                break;

            case 4:
                printf("Seleccionaste 4.\n");
                if (sublista.prim == NULL) {
                    printf("La sublista no ha sido generada. Primero debes seleccionar la opción 2 para generarla.\n");
                    break;
                }

                FILE* archivo = fopen("mayores.bin", "wb");
                if (archivo == NULL) {
                    printf("No se pudo crear el archivo.\n");
                    break;
                }

                nodo_d* actualSublista = sublista.prim;
                while (actualSublista != NULL) {
                    fwrite(actualSublista, sizeof(nodo_d), 1, archivo);
                    actualSublista = actualSublista->sig;
                }
                fclose(archivo);
                printf("La sublista ha sido guardada en el archivo 'mayores.bin'.\n");
                break;

            case 5:
                printf("Seleccionaste 5. Saliendo...\n");
                salida = 1;
                break;

            case 6:
                printf("Seleccionaste 6. Ordenando la lista por edad...\n");
                ordenarListaEdad(&l);
                mostrarLista(l);
                break;

            case 7:
                printf("Seleccionaste 7. Eliminar un dato de la lista principal.\n");
                if (l.prim == NULL) {
                    printf("La lista está vacía.\n");
                    break;
                }
                printf("Ingrese el nombre a eliminar: ");
                getchar();
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = '\0';
                eliminarNodo(&l, nombre);
                mostrarLista(l);
                break;

            default:
                printf("Opción inválida. Inténtalo nuevamente.\n");
                break;
        }
    }

    nodo_d* actual = l.prim;
    while (actual != NULL) {
        nodo_d* siguiente = actual->sig;
        free(actual);
        actual = siguiente;
    }

    actual = sublista.prim;
    while (actual != NULL) {
        nodo_d* siguiente = actual->sig;
        free(actual);
        actual = siguiente;
    }

    return 0;
}
