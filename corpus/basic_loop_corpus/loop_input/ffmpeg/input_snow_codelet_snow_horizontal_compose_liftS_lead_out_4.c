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
    w = 32 * 1024 * 1024 / sizeof(IDWTELEM);
    dst = (IDWTELEM*)aligned_alloc(32, w * sizeof(IDWTELEM));
    src = (IDWTELEM*)aligned_alloc(32, w * sizeof(IDWTELEM));
    ref = (IDWTELEM*)aligned_alloc(32, (w + 1) * sizeof(IDWTELEM));

    for (int j = 0; j < w; j++) {
        src[j] = (IDWTELEM)(j % 32);
        ref[j] = (IDWTELEM)((j + 1) % 32);
        dst[j] = 0;
    }
    ref[w] = (IDWTELEM)(w % 32);

    i = 0;
}