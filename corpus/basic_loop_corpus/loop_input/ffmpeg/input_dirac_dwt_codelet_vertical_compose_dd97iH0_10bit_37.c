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
    width = 65536;

    b0 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b1 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b2 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b3 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b4 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));

    for (i = 0; i < width; i++) {
        b0[i] = rand() % 1000;
        b1[i] = rand() % 1000;
        b2[i] = rand() % 1000;
        b3[i] = rand() % 1000;
        b4[i] = rand() % 1000;
    }
}