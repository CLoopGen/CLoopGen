#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int16_t *coeffs;
int x;
int y;
int size;

void init_vars() {
    size = 8192; // Adjusted to achieve ~0.01 sec runtime
    int total_elements = size * size;
    
    // Allocate memory for coeffs array
    int16_t *coeffs_data = (int16_t*)calloc(total_elements, sizeof(int16_t));
    
    // Initialize with non-zero values to make computation observable
    for (int i = 0; i < total_elements; i++) {
        coeffs_data[i] = rand() % 100;
    }
    
    coeffs = coeffs_data;
    x = 0;
    y = 0;
}