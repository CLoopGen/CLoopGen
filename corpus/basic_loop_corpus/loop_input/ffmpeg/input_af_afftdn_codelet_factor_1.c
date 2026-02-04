#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *array;
int size;

void init_vars() {
    size = 1024; // Choose size such that total memory ~ 8MB (1024*1024*8 bytes), typical for ~0.01s runtime
    array = (double*)calloc(size * size, sizeof(double));
    if (!array) {
        exit(1);
    }

    // Initialize with non-zero values to avoid division by zero
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            array[j + i * size] = (double)(i + j + 1); // Ensure diagonal elements are non-zero
        }
    }
}