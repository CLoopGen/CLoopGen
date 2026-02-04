#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(IDWTELEM)) // ~64MB of data

IDWTELEM *b0;
IDWTELEM *b1;
IDWTELEM *b2;
int width;
int i;

void init_vars() {
    width = DATA_SIZE;

    b0 = (IDWTELEM *)aligned_alloc(32, width * sizeof(IDWTELEM));
    b1 = (IDWTELEM *)aligned_alloc(32, width * sizeof(IDWTELEM));
    b2 = (IDWTELEM *)aligned_alloc(32, width * sizeof(IDWTELEM));

    for (int j = 0; j < width; j++) {
        b0[j] = (IDWTELEM)(j % 128);
        b1[j] = (IDWTELEM)((j + 10) % 256);
        b2[j] = (IDWTELEM)((j + 5) % 128);
    }
}