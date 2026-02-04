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

void init_vars() {
    width = 64 * 1024 * 1024 / sizeof(DWTELEM); // ~256MB total for three arrays, ~85MB each

    b0 = (DWTELEM*)aligned_alloc(32, width * sizeof(DWTELEM));
    b1 = (DWTELEM*)aligned_alloc(32, width * sizeof(DWTELEM));
    b2 = (DWTELEM*)aligned_alloc(32, width * sizeof(DWTELEM));

    if (!b0 || !b1 || !b2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < width; j++) {
        b0[j] = rand() % 100 - 50;
        b1[j] = rand() % 100 - 50;
        b2[j] = rand() % 100 - 50;
    }
}