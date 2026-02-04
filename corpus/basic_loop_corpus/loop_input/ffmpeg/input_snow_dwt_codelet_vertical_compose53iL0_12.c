#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

IDWTELEM *b0;
IDWTELEM *b1;
IDWTELEM *b2;
int width;
int i;

void init_vars() {
    width = 64 * 1024; // 64K elements, ~128KB per array (short = 2 bytes)

    b0 = aligned_alloc(32, width * sizeof(IDWTELEM));
    b1 = aligned_alloc(32, width * sizeof(IDWTELEM));
    b2 = aligned_alloc(32, width * sizeof(IDWTELEM));

    for (int idx = 0; idx < width; idx++) {
        b0[idx] = (IDWTELEM)(idx % 512);
        b1[idx] = (IDWTELEM)(idx % 256);
        b2[idx] = (IDWTELEM)(idx % 128);
    }
}