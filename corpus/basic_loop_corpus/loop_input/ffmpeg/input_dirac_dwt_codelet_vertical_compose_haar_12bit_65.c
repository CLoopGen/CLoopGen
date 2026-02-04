#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
int i;
int32_t *b0;
int32_t *b1;

void init_vars() {
    width = 1 << 20; // Approximately 4MB of data (2^20 elements per array)

    b0 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b1 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));

    if (!b0 || !b1) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < width; j++) {
        b0[j] = (int32_t)(j % 1000);
        b1[j] = (int32_t)((j + 500) % 1500);
    }
}