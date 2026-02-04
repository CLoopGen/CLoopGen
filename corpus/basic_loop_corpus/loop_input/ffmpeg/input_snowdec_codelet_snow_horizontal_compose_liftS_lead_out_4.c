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
    w = 16777216; // ~32 MB of data (16M * sizeof(short) * 2 for src/ref, dst similar)

    dst = (IDWTELEM*)aligned_alloc(32, w * sizeof(IDWTELEM));
    src = (IDWTELEM*)aligned_alloc(32, w * sizeof(IDWTELEM));
    ref = (IDWTELEM*)aligned_alloc(32, (w + 1) * sizeof(IDWTELEM));

    if (!dst || !src || !ref) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < w; j++) {
        src[j] = (IDWTELEM)(j % 512);
        ref[j] = (IDWTELEM)((j + 1) % 512);
        dst[j] = 0;
    }
    ref[w] = (IDWTELEM)(w % 512); // Initialize ref[w] for safe access at i = w-1: ref[i+1]

    i = 0;
}