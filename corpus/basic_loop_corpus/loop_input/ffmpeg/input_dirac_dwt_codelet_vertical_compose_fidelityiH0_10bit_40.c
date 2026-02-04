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

void loop();

void init_vars() {
    width = 16777216;  // 16M elements, roughly 64 MB of total data (8 arrays * 4 bytes * 16M)

    dst = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b0 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b1 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b2 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b3 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b4 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b5 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b6 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));
    b7 = (int32_t*)aligned_alloc(32, width * sizeof(int32_t));

    for (int j = 0; j < width; j++) {
        dst[j] = rand() % 1000;
        b0[j] = rand() % 1000;
        b1[j] = rand() % 1000;
        b2[j] = rand() % 1000;
        b3[j] = rand() % 1000;
        b4[j] = rand() % 1000;
        b5[j] = rand() % 1000;
        b6[j] = rand() % 1000;
        b7[j] = rand() % 1000;
    }
}