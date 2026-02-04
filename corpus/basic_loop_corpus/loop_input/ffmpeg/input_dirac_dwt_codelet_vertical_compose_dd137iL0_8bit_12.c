#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
int i;
int16_t *b0;
int16_t *b1;
int16_t *b2;
int16_t *b3;
int16_t *b4;

void init_vars() {
    width = 16777216; // ~32MB total data (8 arrays of int16_t, each ~32MB / 8 = ~4MB -> 2M elements)

    b0 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b1 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b2 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b3 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b4 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));

    for (i = 0; i < width; i++) {
        b0[i] = rand() % 512;
        b1[i] = rand() % 512;
        b2[i] = rand() % 512;
        b3[i] = rand() % 512;
        b4[i] = rand() % 512;
    }
}