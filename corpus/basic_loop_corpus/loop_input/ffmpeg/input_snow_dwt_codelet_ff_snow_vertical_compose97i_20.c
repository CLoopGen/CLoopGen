#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

#define DATA_SIZE (64 * 1024 * sizeof(IDWTELEM))
#define ARRAY_LEN (DATA_SIZE / sizeof(IDWTELEM))

IDWTELEM *b0;
IDWTELEM *b1;
IDWTELEM *b2;
IDWTELEM *b3;
IDWTELEM *b4;
IDWTELEM *b5;
int width;
int i;

void init_vars() {
    width = ARRAY_LEN;

    b0 = (IDWTELEM*)aligned_alloc(32, DATA_SIZE);
    b1 = (IDWTELEM*)aligned_alloc(32, DATA_SIZE);
    b2 = (IDWTELEM*)aligned_alloc(32, DATA_SIZE);
    b3 = (IDWTELEM*)aligned_alloc(32, DATA_SIZE);
    b4 = (IDWTELEM*)aligned_alloc(32, DATA_SIZE);
    b5 = (IDWTELEM*)aligned_alloc(32, DATA_SIZE);

    for (int j = 0; j < width; j++) {
        b0[j] = (IDWTELEM)(j % 32);
        b1[j] = (IDWTELEM)((j + 1) % 32);
        b2[j] = (IDWTELEM)((j + 2) % 32);
        b3[j] = (IDWTELEM)((j + 3) % 32);
        b4[j] = (IDWTELEM)((j + 4) % 32);
        b5[j] = (IDWTELEM)((j + 5) % 32);
    }
}