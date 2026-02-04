#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

#define DATA_SIZE_MB 64
#define ELEMENT_SIZE sizeof(IDWTELEM)
#define ARRAY_LENGTH ((DATA_SIZE_MB * 1024 * 1024) / ELEMENT_SIZE)

IDWTELEM *b0;
IDWTELEM *b1;
IDWTELEM *b2;
int width;
int i;

void init_vars() {
    width = ARRAY_LENGTH;

    b0 = (IDWTELEM *)aligned_alloc(32, width * sizeof(IDWTELEM));
    b1 = (IDWTELEM *)aligned_alloc(32, width * sizeof(IDWTELEM));
    b2 = (IDWTELEM *)aligned_alloc(32, width * sizeof(IDWTELEM));

    for (int idx = 0; idx < width; idx++) {
        b0[idx] = (IDWTELEM)(idx % 32768);
        b1[idx] = (IDWTELEM)((idx + 10) % 32768);
        b2[idx] = (IDWTELEM)((idx + 20) % 32768);
    }
}