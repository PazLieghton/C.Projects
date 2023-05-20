#include <stdio.h>

// Define the struct
typedef struct {
    char name[10];
    float price;
    
} Pizza;

int main() {
    FILE *file;
    Pizza pizzas[10];

    // Open the file in write mode (binary)
    file = fopen("test1.dat", "wb");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Input pizza details
    for (int i = 0; i < 10; i++) {
        printf("Enter pizza name: ");
        scanf("%9s", pizzas[i].name); // Read up to 9 characters to allow space for null termination
        printf("Enter pizza price: ");
        scanf("%f", &pizzas[i].price);

        // Consume the newline character left in the input buffer
        while (getchar() != '\n')
            continue;
    }

    // Write the array of structs to the file
    fwrite(pizzas, sizeof(Pizza), 10, file);

    // Close the file
    fclose(file);

    // Open the file in read mode (binary)
    file = fopen("test1.dat", "rb");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Read and print the contents of the file
    fread(pizzas, sizeof(Pizza), 10, file);
    printf("\nPizza details:\n");
    for (int i = 0; i < 10; i++) {
        printf("Name: %s\n", pizzas[i].name);
        printf("Price: %.2f\n", pizzas[i].price);
        printf("\n");
    }

    // Close the file
    fclose(file);

    return 0;
}
