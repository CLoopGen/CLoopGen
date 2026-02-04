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
    mul = 17;
    add = 128;
    shift = 8;
    i = 0;

    dst = (IDWTELEM *)aligned_alloc(32, (w + 1) * sizeof(IDWTELEM));
    src = (IDWTELEM *)aligned_alloc(32, (w + 1) * sizeof(IDWTELEM));
    ref = (IDWTELEM *)aligned_alloc(32, (w + 1) * sizeof(IDWTELEM));

    for (int j = 0; j < w + 1; j++) {
        dst[j] = 0;
        src[j] = (IDWTELEM)(j & 0xFF);
        ref[j] = (IDWTELEM)((j * 3) & 0x1FF);
    }
}