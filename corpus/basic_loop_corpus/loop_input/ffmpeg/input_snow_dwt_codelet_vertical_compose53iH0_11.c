#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

#define DATA_SIZE (1 << 20)  // Approximately 1MB: 2^20 elements

IDWTELEM *b0;
IDWTELEM *b1;
IDWTELEM *b2;
int width;
int i;

void init_vars() {
    width = DATA_SIZE;

    b0 = (IDWTELEM*)aligned_alloc(32, width * sizeof(IDWTELEM));
    b1 = (IDWTELEM*)aligned_alloc(32, width * sizeof(IDWTELEM));
    b2 = (IDWTELEM*)aligned_alloc(32, width * sizeof(IDWTELEM));

    for (int idx = 0; idx < width; idx++) {
        b0[idx] = (IDWTELEM)(idx % 32768);
        b1[idx] = (IDWTELEM)((idx + 1) % 32768);
        b2[idx] = (IDWTELEM)((idx + 2) % 32768);
    }
}