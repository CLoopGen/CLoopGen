#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

int i;
IDWTELEM *dst;
IDWTELEM *src;
IDWTELEM *ref;
int w;

void init_vars() {
    w = 6710886;  // ~13.4MB of data per array (6.7M elements * 2 bytes)
    dst = (IDWTELEM*)aligned_alloc(32, w * sizeof(IDWTELEM));
    src = (IDWTELEM*)aligned_alloc(32, w * sizeof(IDWTELEM));
    ref = (IDWTELEM*)aligned_alloc(32, w * sizeof(IDWTELEM));

    for (int j = 0; j < w; j++) {
        src[j] = (IDWTELEM)(j % 32768);
        ref[j] = (IDWTELEM)((j * 3) % 32768);
        dst[j] = 0;
    }

    i = 0;
}