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
int mul;
int add;
int shift;

void init_vars() {
    w = 65536;  
    mul = 2;
    add = 1;
    shift = 2;
    i = 0;

    dst = (IDWTELEM *)aligned_alloc(32, w * sizeof(IDWTELEM));
    src = (IDWTELEM *)aligned_alloc(32, w * sizeof(IDWTELEM));
    ref = (IDWTELEM *)aligned_alloc(32, (w + 1) * sizeof(IDWTELEM));

    for (int j = 0; j < w; j++) {
        dst[j] = 0;
        src[j] = (IDWTELEM)(j % 32768);
    }
    for (int j = 0; j < w + 1; j++) {
        ref[j] = (IDWTELEM)((j * 2) % 32768);
    }
}