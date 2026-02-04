#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

IDWTELEM *b;
IDWTELEM *temp;
int w_r;
int i;
IDWTELEM *src;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data to ensure ~0.01s runtime
    w_r = (data_size / sizeof(IDWTELEM)) / 2;  // Adjust so that arrays have enough elements
    w_r = (w_r / 8) * 8; // Ensure w_r is multiple of 8 for safe vectorization

    b = aligned_alloc(16, sizeof(IDWTELEM) * (w_r + 10));
    temp = aligned_alloc(16, sizeof(IDWTELEM) * (w_r + 10));
    src = aligned_alloc(16, sizeof(IDWTELEM) * (w_r + 10));

    for (int j = 0; j < w_r + 10; j++) {
        b[j] = rand() % 100;
        temp[j] = 0;
        src[j] = rand() % 100;
    }

    i = 0;
}