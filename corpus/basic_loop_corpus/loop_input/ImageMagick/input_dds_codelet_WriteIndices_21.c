#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

unsigned char *indices;
ssize_t i;
size_t a;
size_t b;
unsigned char remapped[16];

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    indices = (unsigned char *)malloc(data_size);
    if (!indices) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize indices with sample data (0 to 255 repeating pattern)
    for (size_t j = 0; j < data_size; j++) {
        indices[j] = (unsigned char)(j % 256);
    }

    // Initialize a and b to trigger the first branch (a < b)
    a = 5;
    b = 10;

    // Initialize remapped array to zero
    memset(remapped, 0, sizeof(remapped));
}