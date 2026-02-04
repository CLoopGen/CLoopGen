#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int width;
int i;
int32_t *b0;
int32_t *b1;
int32_t *b2;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data to ensure ~0.01s runtime
    width = data_size / sizeof(int32_t);

    b0 = (int32_t*)aligned_alloc(32, data_size);
    b1 = (int32_t*)aligned_alloc(32, data_size);
    b2 = (int32_t*)aligned_alloc(32, data_size);

    if (!b0 || !b1 || !b2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (int j = 0; j < width; j++) {
        b0[j] = rand() % 1000;
        b1[j] = rand() % 1000;
        b2[j] = rand() % 1000;
    }
}