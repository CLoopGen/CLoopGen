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
    width = 65536; // Size chosen to process ~131KB per array, total ~393KB of data

    b0 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b1 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));
    b2 = (int16_t*)aligned_alloc(32, width * sizeof(int16_t));

    if (!b0 || !b1 || !b2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (i = 0; i < width; i++) {
        b0[i] = rand() % 256;
        b1[i] = rand() % 256;
        b2[i] = rand() % 256;
    }
}