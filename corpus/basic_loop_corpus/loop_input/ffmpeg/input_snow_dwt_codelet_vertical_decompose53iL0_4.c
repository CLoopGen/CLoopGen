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

static DWTELEM *data_b0;
static DWTELEM *data_b1;
static DWTELEM *data_b2;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~256 MB total for three arrays (64M * 4 bytes * 3)
    width = data_size / sizeof(DWTELEM);

    data_b0 = aligned_alloc(32, width * sizeof(DWTELEM));
    data_b1 = aligned_alloc(32, width * sizeof(DWTELEM));
    data_b2 = aligned_alloc(32, width * sizeof(DWTELEM));

    b0 = data_b0;
    b1 = data_b1;
    b2 = data_b2;

    for (int j = 0; j < width; j++) {
        b0[j] = (DWTELEM)(j % 128);
        b1[j] = (DWTELEM)((j + 16) % 256);
        b2[j] = (DWTELEM)((j + 32) % 128);
    }
}