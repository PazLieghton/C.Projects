#include <stdio.h>
#include <stdlib.h>

//Ejemplo de lector doble//

typedef struct nodo_d {
    char nombre[100];
    int edad;
    struct nodo_d* ant, * sig;
} nodo_d;

int main() {
    FILE* archivo = fopen("mayores.bin", "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    nodo_d* actual = (nodo_d*)malloc(sizeof(nodo_d));
    while (fread(actual, sizeof(nodo_d), 1, archivo) == 1) {
        printf("Nombre: %s, Edad: %d\n", actual->nombre, actual->edad);
    }

    free(actual);
    fclose(archivo);

    return 0;
}
