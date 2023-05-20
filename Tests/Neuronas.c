#include <stdio.h>
#include <stdlib.h>
// Define the struct
typedef struct {
    int neurona;
    double activacion;
    
} Neurona;

int main() {
    FILE *file;
    Neurona neuronas[10];

    // Open the file in write mode (binary)
    file = fopen("test2.dat", "wb");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Input pizza details
    for (int i = 0; i < 10; i++) {
        printf("Ingrese Numero de Neurona: ");
        scanf("%d", &neuronas[i].neurona); // Read up to 9 characters to allow space for null termination
        printf("Ingrese nivel de activacion de neurona: ");
        scanf("%lf", &neuronas[i].activacion);

        // Consume the newline character left in the input buffer
        while (getchar() != '\n')
            continue;
    }

    // Write the array of structs to the file
    fwrite(neuronas, sizeof(Neurona), 10, file);

    // Close the file
    fclose(file);

    // Open the file in read mode (binary)
    file = fopen("test2.dat", "rb");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Read and print the contents of the file
    fread(neuronas, sizeof(Neurona), 10, file);
    printf("\nNeuronas:\n");
    for (int i = 0; i < 10; i++) {
        printf("Neurona Numero: %d\n", neuronas[i].neurona);
        printf("Activacion: %.2lf\n", neuronas[i].activacion);
        printf("\n");
    }

    // Close the file
    fclose(file);

    return 0;
}
