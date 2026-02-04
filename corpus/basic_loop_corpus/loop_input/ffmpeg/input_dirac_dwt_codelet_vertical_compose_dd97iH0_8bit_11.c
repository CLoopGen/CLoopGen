#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int width;
int i;
int16_t *b0;
int16_t *b1;
int16_t *b2;
int16_t *b3;
int16_t *b4;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data to ensure ~0.01s runtime
    width = data_size / sizeof(int16_t);

    b0 = (int16_t*)aligned_alloc(32, data_size);
    b1 = (int16_t*)aligned_alloc(32, data_size);
    b2 = (int16_t*)aligned_alloc(32, data_size);
    b3 = (int16_t*)aligned_alloc(32, data_size);
    b4 = (int16_t*)aligned_alloc(32, data_size);

    if (!b0 || !b1 || !b2 || !b3 || !b4) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (int j = 0; j < width; j++) {
        b0[j] = (int16_t)(rand() % 65536 - 32768);
        b1[j] = (int16_t)(rand() % 65536 - 32768);
        b2[j] = (int16_t)(rand() % 65536 - 32768);
        b3[j] = (int16_t)(rand() % 65536 - 32768);
        b4[j] = (int16_t)(rand() % 65536 - 32768);
    }
}