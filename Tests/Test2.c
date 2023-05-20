#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int neurona;
    double activacion;
} Neurona;



typedef struct nodo1{
    int identificador;
    struct nodo1 *sig;
} nodo1;


typedef struct nodo2{
	double activation;
	struct nodo2 *sig;
} nodo2;

//CARGAR ARCHIVOS//
//PARTE 1//
void cargar_neuronas(Neurona neuronas [])
{
    FILE *f;
    int n;
    
    f = fopen ("test2.dat", "rb");
    if (f == NULL) {
        printf ("Error al abrir el archivo de Neuronas\n");
        return;
    }
    n = fread (neuronas, sizeof (neuronas [0]), 10, f);
    if (n != 10) {
        printf ("Error: se leyeron menos de 10 neuronas\n");
        fclose (f);
        return;
    }
    if (fclose (f) != 0) {
        printf ("Error al cerrar el archivo de neuronas\n");
        return;
        }
    printf ("Archivo de neuronas cargado ok\n");
}

//
//PARTE 5//
void mostrar_archivo(Neurona neuronas [])
{
    int i;
    printf ("Identificador             Activacion\n");
    for (i=0; i < 10; i++)
        printf ("%d  ------------------------ %lf\n", neuronas[i].neurona, neuronas[i].activacion);
}

//



//FIFO//
nodo1* insertar_fifo(nodo1* l, int identificador) {
    nodo1* nuevo = (nodo1*)malloc(sizeof(nodo1));
    nuevo->identificador = identificador;
    nuevo->sig = NULL;

    if (l == NULL) {
        return nuevo;
    } else {
        nodo1* p = l;
        while (p->sig != NULL) {
            p = p->sig;
        }
        p->sig = nuevo;
        return l;
    }
}

//LIFO//
nodo2* insertar_lifo(nodo2* l, double activation) {
    nodo2* nuevo = (nodo2*)malloc(sizeof(nodo2));
    nuevo->activation = activation;
    nuevo->sig = l;
    return nuevo;
}



void mostrar_nodo1(nodo1* l) {
    if (l == NULL) {
        printf("La lista nodo1 está vacía.\n");
    } else {
        nodo1* p = l;
        printf("Contenido de la lista de IDENTIFICADORES:\n");
        while (p != NULL) {
            printf("%d ", p->identificador);
            p = p->sig;
        }
        printf("\n");
    }
}

void mostrar_nodo2(nodo2* l) {
    if (l == NULL) {
        printf("La lista nodo2 está vacía.\n");
    } else {
        nodo2* p = l;
        printf("Contenido de la lista de ACTIVADORES:\n");
        while (p != NULL) {
            printf("%lf ", p->activation);
            p = p->sig;
        }
        printf("\n");
    }
}
//DIFERENCIAS
double modo_activacion_cercano_a_uno(nodo2* l) {
    if (l == NULL) {
        printf("La lista nodo2 está vacía.\n");
        return -1.0; // Valor de retorno inválido en caso de lista vacía
    } else {
        double modo_cercano = l->activation;
        double diferencia_minima = fabs(1.0 - l->activation);

        nodo2* p = l->sig;
        while (p != NULL) {
            double diferencia = fabs(1.0 - p->activation);
            if (diferencia < diferencia_minima) {
                modo_cercano = p->activation;
                diferencia_minima = diferencia;
            }
            p = p->sig;
        }
        return modo_cercano;
    }
}

//INTERCAMBIAR//
void cambiar_posicion_nodo2(nodo2* l, int posicion, double nuevo_valor) {
    nodo2* p = l;
    int contador = 0;

    while (p != NULL && contador < posicion) {
        p = p->sig;
        contador++;
    }

    if (p != NULL) {
        p->activation = nuevo_valor;
        printf("Se cambió el valor en la posición %d por %lf\n", posicion, nuevo_valor);
    } else {
        printf("La posición %d está fuera de rango\n", posicion);
    }
}

//INTERCAMBIAR PRIMERO ULTIMO//
nodo1* intercambiar_primero_ultimo(nodo1* l) {
    if (l == NULL || l->sig == NULL) {
        // Lista vacía o con un solo nodo, no hay cambios que hacer
        return l;
    } else {
        nodo1* p = l;
        nodo1* anterior = NULL;

        // Recorrer hasta el último nodo
        while (p->sig != NULL) {
            anterior = p;
            p = p->sig;
        }

        // Intercambiar los valores del primer y último nodo
        int temp = l->identificador;
        l->identificador = p->identificador;
        p->identificador = temp;

        return l;
    }
}





void liberar_nodo1(nodo1* l) {
    nodo1* actual = l;
    while (actual != NULL) {
        nodo1* siguiente = actual->sig;
        free(actual);
        actual = siguiente;
    }
}

void liberar_nodo2(nodo2* l) {
    nodo2* actual = l;
    while (actual != NULL) {
        nodo2* siguiente = actual->sig;
        free(actual);
        actual = siguiente;
    }
}



void guardar_archivo(nodo1* identif, nodo2* activ) {
    FILE* f = fopen("gaa.dat", "wb");
    if (f == NULL) {
        printf("Error al abrir el archivo de salida\n");
        return;
    }

    // Contar la cantidad de elementos en las listas nodo1 y nodo2
    int count1 = 0;
    int count2 = 0;
    nodo1* p1 = identif;
    nodo2* p2 = activ;
    while (p1 != NULL) {
        count1++;
        p1 = p1->sig;
    }
    while (p2 != NULL) {
        count2++;
        p2 = p2->sig;
    }

    // Crear un array de Neurona para almacenar los datos de los nodos
    Neurona* neuronas = (Neurona*)malloc(sizeof(Neurona) * count1);
    if (neuronas == NULL) {
        printf("Error al asignar memoria\n");
        fclose(f);
        return;
    }

    // Llenar el array de Neurona con los datos de los nodos
    p1 = identif;
    p2 = activ;
    for (int i = 0; i < count1; i++) {
        neuronas[i].neurona = p1->identificador;
        neuronas[i].activacion = p2->activation;
        p1 = p1->sig;
        p2 = p2->sig;
    }

    // Escribir el array de Neurona en el archivo
    int n = fwrite(neuronas, sizeof(Neurona), count1, f);
    if (n != count1) {
        printf("Error al escribir los datos en el archivo\n");
    } else {
        printf("Archivo guardado correctamente\n");
    }

    // Liberar la memoria y cerrar el archivo
    free(neuronas);
    fclose(f);
}






int main()
{
	Neurona neuronas[10];
	int op;
	nodo1 *identif = NULL;
	nodo2 *activ = NULL;
	do{
		printf("\n1. Leer Y Almacenar el Archivo\n2. Nivel de activacion mas cercano a 1\n3. Intercambiar identificadores de posicion\n4. Generar un Archivo\n");
		printf("5. Mostrar Listas\n6. Salir\nIngrese opcion:  ");
		scanf ("%d", &op);
		switch(op){
            case 1:
            	cargar_neuronas (neuronas);
            	for (int i = 0; i < 10; i++) {
                    identif = insertar_fifo(identif, neuronas[i].neurona);
                }
                for (int i = 0; i < 10; i++) {
                    activ = insertar_lifo(activ, neuronas[i].activacion);
                }
                break;
    	    case 2:
        		double modo_cercano = modo_activacion_cercano_a_uno(activ);
		        printf("Modo de activación más cercano a uno: %lf\n", modo_cercano);
   				 break;
 
            case 3:
            	int posicion;
   			    double nuevo_valor;
		        printf("Ingrese la posición del nodo a cambiar: ");
        		scanf("%d", &posicion);
        		printf("Ingrese el nuevo valor: ");
        		scanf("%lf", &nuevo_valor);
       			cambiar_posicion_nodo2(activ, posicion, nuevo_valor);
                identif = intercambiar_primero_ultimo(identif);
                break;
			case 4:
			    guardar_archivo(identif, activ);
			    break;

            case 5:
            	mostrar_archivo(neuronas);
            	printf("\n\n\n");
            	mostrar_nodo1(identif);
            	mostrar_nodo2(activ);
                break;
				case 6:
			    liberar_nodo1(identif);
 			    liberar_nodo2(activ);
   				printf("Memoria liberada. Saliendo del programa...\n");
			    break;

            default:
                printf ("OPCION INVALIDA\n");
        }

	}while (op != 6);


	return 0;
}