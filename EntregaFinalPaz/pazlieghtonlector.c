#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
    unsigned char vectorchar[100];
} vector;

int main() {
    FILE* archivo = fopen("filtrado.dat", "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    vector Sublista;
    while (fread(&Sublista.vectorchar, sizeof(unsigned char), 1, archivo) == 1) {
        printf("Letra guardada: %c\n", Sublista.vectorchar[0] );
}
    fclose(archivo);
    return 0;
}
