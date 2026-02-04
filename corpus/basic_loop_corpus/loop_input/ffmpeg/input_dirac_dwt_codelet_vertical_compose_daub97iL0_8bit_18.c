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
    width = 1 << 18; // Approximately 256KB of data per array (3 arrays), total ~768KB, ensures loop runs about 0.01s

    b0 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b1 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b2 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));

    for (i = 0; i < width; i++) {
        b0[i] = rand() % 1000 - 500;
        b1[i] = rand() % 1000 - 500;
        b2[i] = rand() % 1000 - 500;
    }
}