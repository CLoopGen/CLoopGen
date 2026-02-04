#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int DWTELEM;

DWTELEM *b0;
DWTELEM *b1;
DWTELEM *b2;
int width;
int i;

static DWTELEM *alloc_aligned_array(size_t count) {
    void *ptr;
    if (posix_memalign(&ptr, 32, count * sizeof(DWTELEM)) != 0) {
        exit(1);
    }
    return (DWTELEM *)ptr;
}

void init_vars() {
    width = 16777216; 

    b0 = alloc_aligned_array(width);
    b1 = alloc_aligned_array(width);
    b2 = alloc_aligned_array(width);

    for (int j = 0; j < width; j++) {
        b0[j] = rand() % 1000;
        b1[j] = rand() % 1000;
        b2[j] = rand() % 1000;
    }
}