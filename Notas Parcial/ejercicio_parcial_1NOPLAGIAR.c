/*
Se tiene un archivo binario procesadores.dat conteniendo valores enteros que representan
informacion de procesadores de computadora.
EL significado de cada entero es las siguiente codificacion. Tiene 8 digitos: MMMMMvvv.
Es decir los 3 digitos menos significativos representan la velocidad y los 5 restantes son el modelo
Se pide implementar un menu ciclico que permita las siguientes opciones:

1. Cear una lista FIFO de procesadores a partir del archivo
2. Eliminar procesador ingresando el modelo (5 digitos maximo)
3. Mostrar primero y penultimo procesador de la lista
4. Mostrar modelo y velocidad del procesador mas rapido y mas lento
5. Agregar un procesador al principio de la lista ingresando modelo y velocidad por separado
6. Imprimir lista actual
--------------------------------------------------------------------------------------------
7. OPCION EXTRA: Crear un archivo 'procesadores.dat' ingresando valores a mano.
8. OPCION EXTRA: Imprimir los valores que tiene el archivo 'procesadores.dat'
9. OPCION EXTRA: Guardar la lista en el archivo 'procesadores.dat'
--------------------------------------------------------------------------------------------
0. Salir
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int proc;
    struct nodo* sig;
}nodo;


int obtener_modelo_procesador(int procesador) {
    int a;
    a = procesador / 1000; // Ej. 12345090 => 12345
    printf("a vale: %d\n", a);
    return a;
}

int obtener_velocidad_procesador(int procesador) {
    int a;
    a = procesador % 1000; // Ej. 12345090 => 90
    printf("a vale: %d\n", a);
    return a;
}


nodo* insertar_fifo(nodo* lista, int procesador) {
    nodo* nuevo, * p;

    nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->proc = procesador;
    nuevo->sig = NULL;
    if (lista == NULL)
        return nuevo;
    p = lista;
    while (p->sig != NULL)
        p = p->sig;
    p->sig = nuevo;
    return lista;
}


nodo* crea_lista_desde_archivo(nodo* lista) {
    FILE* f;
    int cant = 0, n, procesador;

    f = fopen("procesadores.dat", "rb");
    if (f == NULL) {
        printf("\nError al abrir");
        return NULL;
    }
    n = fread(&procesador, sizeof(int), 1, f);
    while (n == 1) {
        cant++;
        lista = insertar_fifo(lista, procesador);
        n = fread(&procesador, sizeof(int), 1, f);
    }
    if (fclose(f) != 0) {
        printf("\nError al cerrar");
        return NULL;
    }
    printf("%d registros leidos desde archivo\n", cant);

    return lista;
}


void mostrar_primero_penultimo(nodo* lista) {
    if (lista == NULL) {
        printf("No hay procesadores en la lista\n");
    }
    else if (lista->sig == NULL) {
        printf("Unico procesador de la lista: %d\n", lista->proc);
    }
    else if (lista->sig->sig == NULL) {
        printf("Hay solo dos procesadores en la lista\n");
        printf("Primer y penultimo procesador de la lista: %d\n", lista->proc);
    }
    else {
        printf("Primer procesador de la lista %d \n", lista->proc);
        while (lista->sig->sig != NULL) {
            lista = lista->sig;
        }
        printf("Penultimo procesador de la lista: %d\n", lista->proc);
    }
}


void mostrar_proc_rapido_lento(nodo* lista) {
    int mayor, menor, procMay, procMen;
    if (lista == NULL) {
        printf("Lista vacia\n");
        return;
    }
    else {
        procMay = lista->proc;
        procMen = lista->proc;
        mayor = lista->proc % 1000;
        menor = lista->proc % 1000;
        while (lista != NULL) {
            if (lista->proc % 1000 > mayor) {
                mayor = lista->proc % 1000;
                procMay = lista->proc;
            }
            if (lista->proc % 1000 < menor) {
                menor = lista->proc % 1000;
                procMen = lista->proc;
            }
            lista = lista->sig;
        }
    }
    printf("El codigo del procesador de mayor velocidad es: %d - Su velocidad es: %d\n", procMay / 1000, procMay % 1000);
    printf("El codigo del procesador de menor velocidad es: %d - Su velocidad es: %d\n", procMen / 1000, procMen % 1000);
}


void mostrar_lista(nodo* lista) {
    printf("Contenido de la lista:\n");
    while (lista != NULL) {
        printf("Codigo %d - Velocidad %d Mhz\n", lista->proc / 1000, lista->proc % 1000);
        lista = lista->sig;
    }
    return;
}

nodo* agregar_proc_principio(nodo* lista) {
    int codigo, velocidad, procesador;
    nodo* nuevo;

    printf("Ingrese codigo del procesador (debe tener 5 digitos)\n");
    scanf("%d", &codigo);
    printf("Ingrese velocidad del procesador (3 digitos maximo)\n");
    scanf("%d", &velocidad);
    procesador = (codigo * 1000) + velocidad;
    printf("procesador ingresado: %d\n----------\n", procesador);
    nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->proc = procesador;
    nuevo->sig = lista;
    return nuevo;
}


//Recibe en d los 5 digitos
nodo* eliminar_proc(nodo* lista, int d) {
    nodo* ret = lista, * aux;

    if (lista != NULL) {
        if (lista->proc / 1000 == d) {
            ret = lista->sig;
            free(lista);
            printf("Se elimino el procesador  '%d'\n", d);
        }
        else {
            while (lista->sig != NULL && lista->sig->proc / 1000 != d)
                lista = lista->sig;
            if (lista->sig != NULL) {
                aux = lista->sig;
                lista->sig = aux->sig;
                free(aux);
                printf("Se elimino el procesador '%d'\n", d);
            }
            else
                printf("No hubo eliminaciones: EL PROCESADOR '%d' NO EXISTE\n", d);
        }
    }
    else
        printf("No hubo eliminaciones: Lista vacia\n");

    return ret;
}


void mostrarContenidoDeArchivo(void) {
    FILE* f;
    int cant = 0, n, procesador;

    f = fopen("procesadores.dat", "rb");

    if (f == NULL) {
        printf("\nError al abrir el archivo");
        return;
    }
    n = fread(&procesador, sizeof(int), 1, f);
    while (n == 1) {
        cant++;
        printf("%02d Valor leido: %d \n", cant, procesador);
        n = fread(&procesador, sizeof(int), 1, f);
    }
    if (fclose(f) != 0) {
        printf("\nError al cerrar el archivo");
        return;
    }
    return;
}


void generarNuevoArchivoPersonalizado(void) {
    FILE* f;
    int cant = 0, n, codigo, op = 1;

    f = fopen("procesadores.dat", "wb");
    if (f == NULL) {
        printf("\nError al crear archivo\n");
        return;
    }

    while (op != 0) {
        printf("\nIngrese un codigo de procesador (8 digitos): ");
        scanf("%d", &codigo);
        n = fwrite(&codigo, sizeof(int), 1, f);
        if (n == 0) {
            printf("\nError al escribir en el archivo\n");
            exit(1);
        }
        printf("\nContinuar? -> 1\n");
        printf("\n    Salir? -> 0\n");
        scanf("%d", &op);
        cant++;
    }
    printf("\nSe grabaron %d valores en procesadores.dat\n", cant);
    if (fclose(f) != 0) {
        printf("\nError al cerrar el archivo");
        return;
    }
    return;
}


void guardarListaEnArchivo(nodo* lista) {
    FILE* f;
    int cant = 0, n;

    f = fopen("procesadores.dat", "wb");
    if (f == NULL) {
        printf("\nError al crear archivo\n");
        return;
    }
    while (lista != NULL) {
        n = fwrite(&lista->proc, sizeof(int), 1, f);
        if (n == 0) {
            printf("\nError al escribir en el archivo\n");
            exit(1);
        }
        lista = lista->sig;
        cant++;
    }
    printf("\nSe grabaron %d valores en procesadores.dat\n", cant);
    if (fclose(f) != 0) {
        printf("\nError al cerrar");
        return;
    }
    return;
}


int imprime_menu(void) {
    int op;

    printf("\n1. Cear lista FIFO de procesadores desde archivo");
    printf("\n2. Eliminar procesador ingresando el modelo (5 digitos maximo)");
    printf("\n3. Mostrar primero y penultimo procesador de la lista");
    printf("\n4. Mostrar modelo y velocidad del procesador mas rapido y mas lento");
    printf("\n5. Agregar un procesador al principio de la lista ingresando modelo y velocidad por separado");
    printf("\n6. Imprimir lista actual");
    printf("\n--------------------------------------------------------------------------------------------");
    printf("\n7. OPCION EXTRA: Crear un archivo 'procesadores.dat' ingresando valores a mano.");
    printf("\n8. OPCION EXTRA: Imprimir los valores que tiene el archivo 'procesadores.dat'");
    printf("\n9. OPCION EXTRA: Guardar la lista en el archivo 'procesadores.dat'");
    printf("\n--------------------------------------------------------------------------------------------");
    printf("\n0. Salir");
    printf("\nOpcion:");
    scanf("%d", &op);
    return op;
}


int main() {
    int op, codigo;
    nodo* lista = NULL;

    do {
        op = imprime_menu();
        switch (op) {
        case 1:
            lista = crea_lista_desde_archivo(lista);
            break;
        case 2:
            printf("Ingrese el modelo del procesador a eliminar (5 digitos): \n");
            scanf("%d", &codigo);
            lista = eliminar_proc(lista, codigo);
            break;
        case 3:
            mostrar_primero_penultimo(lista);
            break;
        case 4:
            mostrar_proc_rapido_lento(lista);
            break;
        case 5:
            lista = agregar_proc_principio(lista);
            break;
        case 6:
            mostrar_lista(lista);
            break;
        case 7:
            generarNuevoArchivoPersonalizado();
            break;
        case 8:
            mostrarContenidoDeArchivo();
            break;
        case 9:
            guardarListaEnArchivo(lista);
            break;
        case 0:
            break;
        default:
            printf("\nOpcion invalida");
            break;
        }
    } while (op != 0);

    return 0;
}
