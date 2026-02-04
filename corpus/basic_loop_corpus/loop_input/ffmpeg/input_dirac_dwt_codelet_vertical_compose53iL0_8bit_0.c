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
    width = 67108864;  // ~134MB of total data (3 arrays), aiming for ~0.01 sec on modern CPU

    b0 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b1 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b2 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));

    for (i = 0; i < width; i++) {
        b0[i] = (int16_t)(i % 32768);
        b1[i] = (int16_t)((i + 1) % 32768);
        b2[i] = (int16_t)((i + 2) % 32768);
    }
}