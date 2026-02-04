#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
int i;
int16_t *b0;
int16_t *b1;
int16_t *b2;

void init_vars() {
    width = 1 << 20; // Approximately 1MB of data per array (each int16_t is 2 bytes, 3 arrays)

    b0 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b1 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b2 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));

    if (!b0 || !b1 || !b2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (i = 0; i < width; i++) {
        b0[i] = rand() % 1000;
        b1[i] = rand() % 1000;
        b2[i] = rand() % 1000;
    }
}