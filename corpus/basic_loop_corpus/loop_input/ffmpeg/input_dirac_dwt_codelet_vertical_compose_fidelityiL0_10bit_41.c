#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
int i;
int32_t *dst;
int32_t *b0;
int32_t *b1;
int32_t *b2;
int32_t *b3;
int32_t *b4;
int32_t *b5;
int32_t *b6;
int32_t *b7;

void init_vars() {
    width = 1 << 20;  // Approximately 1 million elements

    dst = aligned_alloc(32, width * sizeof(int32_t));
    b0 = aligned_alloc(32, width * sizeof(int32_t));
    b1 = aligned_alloc(32, width * sizeof(int32_t));
    b2 = aligned_alloc(32, width * sizeof(int32_t));
    b3 = aligned_alloc(32, width * sizeof(int32_t));
    b4 = aligned_alloc(32, width * sizeof(int32_t));
    b5 = aligned_alloc(32, width * sizeof(int32_t));
    b6 = aligned_alloc(32, width * sizeof(int32_t));
    b7 = aligned_alloc(32, width * sizeof(int32_t));

    for (i = 0; i < width; i++) {
        dst[i] = rand() % 1000;
        b0[i] = rand() % 1000;
        b1[i] = rand() % 1000;
        b2[i] = rand() % 1000;
        b3[i] = rand() % 1000;
        b4[i] = rand() % 1000;
        b5[i] = rand() % 1000;
        b6[i] = rand() % 1000;
        b7[i] = rand() % 1000;
    }
}