#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

ssize_t i;
double *squares;

void init_vars() {
    // Allocate enough memory to cover index range [-255, 255]
    // We need at least 256 (for -255..-1) + 1 (for 0) + 256 (for 1..255) = 512 elements
    // But we must allow indexing from -255, so we allocate extra space and set base pointer accordingly.
    size_t total_elements = 512;
    double *storage = (double *)calloc(total_elements, sizeof(double));
    
    // Set squares pointer so that index -255 points to the first allocated element
    squares = &storage[255];

    // Initialize loop index
    i = -255;
}