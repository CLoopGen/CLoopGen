#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
int i;
int16_t *dst;
int16_t *b0;
int16_t *b1;
int16_t *b2;
int16_t *b3;
int16_t *b4;
int16_t *b5;
int16_t *b6;
int16_t *b7;

void init_vars() {
    width = 65536; // Adjusted for ~0.01s runtime

    dst = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b0 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b1 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b2 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b3 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b4 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b5 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b6 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b7 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));

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