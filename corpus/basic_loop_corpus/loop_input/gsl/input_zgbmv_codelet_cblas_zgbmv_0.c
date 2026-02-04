#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

void *Y;
int incY;
int i;
int lenY;
int iy;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 MB of double complex data (each element is 2 doubles)
    const size_t num_elements = data_size / (2 * sizeof(double));

    lenY = num_elements;
    iy = 0;
    incY = 1;

    Y = aligned_alloc(32, data_size);
    if (!Y) {
        exit(1);
    }
}