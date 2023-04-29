#include <stdio.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40

void render_cube(float angle) {
    char framebuffer[HEIGHT][WIDTH];
    float cube_size = 10.0;
    float camera_distance = 20.0;

    // Calculate rotation matrix
    float cos_angle = cos(angle);
    float sin_angle = sin(angle);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Convert screen coordinates to normalized device coordinates
            float ndc_x = (2.0 * x / WIDTH) - 1.0;
            float ndc_y = (2.0 * y / HEIGHT) - 1.0;

            // Rotate the ray direction
            float ray_dir_x = (ndc_x * cos_angle) - (ndc_y * sin_angle);
            float ray_dir_y = (ndc_x * sin_angle) + (ndc_y * cos_angle);

            // Calculate ray direction from camera
            ray_dir_x *= cube_size / camera_distance;
            ray_dir_y *= cube_size / camera_distance;

            // Check if the ray intersects with the cube
            if (ray_dir_x >= -cube_size && ray_dir_x <= cube_size &&
                ray_dir_y >= -cube_size && ray_dir_y <= cube_size) {
                // Set the character to represent the cube
                framebuffer[y][x] = '#';
            } else {
                // Set the character to represent empty space
                framebuffer[y][x] = ' ';
            }
        }
    }

    // Print the framebuffer to the terminal
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", framebuffer[y][x]);
        }
        printf("\n");
    }
}

int main() {
    float angle = 0.0;
    float angular_velocity = 0.1; // Adjust this to change spinning speed

    while (1) {
        // Clear the terminal
        printf("\033c");
        render_cube(angle);
        angle += angular_velocity;
    }

    return 0;
}

