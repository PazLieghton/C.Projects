#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
    unsigned char vectorchar[100];
    int posicion;
} vector;

int main() {
    FILE* archivo = fopen("datos.bin", "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    vector Sublista;
    while (fread(&Sublista.vectorchar, sizeof(unsigned char), 1, archivo) == 1 &&
           fread(&Sublista.posicion, sizeof(int), 1, archivo) == 1) {
        printf("Vector: %c, Posición: %d\n", Sublista.vectorchar[0], Sublista.posicion);
    }

    fclose(archivo);
    return 0;
}
