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

static IDWTELEM *alloc_aligned_array(size_t count) {
    void *ptr;
    if (posix_memalign(&ptr, 32, count * sizeof(IDWTELEM)) != 0) {
        exit(1);
    }
    return (IDWTELEM *)ptr;
}

void init_vars() {
    w = 6710886; // ~13.4MB per array, total ~40MB; adjust to target runtime
    i = 0;

    dst = alloc_aligned_array(w);
    src = alloc_aligned_array(w);
    ref = alloc_aligned_array(w);

    for (int j = 0; j < w; j++) {
        src[j] = (IDWTELEM)(j % 32768);
        ref[j] = (IDWTELEM)((j * 3) % 32768);
    }
}