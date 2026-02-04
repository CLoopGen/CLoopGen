#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
int i;

int32_t *b0;
int32_t *b1;
int32_t *b2;
int32_t *b3;
int32_t *b4;

void init_vars() {
    width = 64 * 1024 * 1024 / sizeof(int32_t); // ~256MB total data, each array gets ~64MB

    b0 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b1 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b2 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b3 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b4 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));

    if (!b0 || !b1 || !b2 || !b3 || !b4) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < width; j++) {
        b0[j] = rand() % 1000;
        b1[j] = rand() % 1000;
        b2[j] = rand() % 1000;
        b3[j] = rand() % 1000;
        b4[j] = rand() % 1000;
    }
}