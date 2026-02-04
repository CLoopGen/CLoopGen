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
    width = 64 * 1024; // 64k elements per array, roughly 256KB total for three arrays

    b0 = (DWTELEM*)aligned_alloc(32, width * sizeof(DWTELEM));
    b1 = (DWTELEM*)aligned_alloc(32, width * sizeof(DWTELEM));
    b2 = (DWTELEM*)aligned_alloc(32, width * sizeof(DWTELEM));

    for (int j = 0; j < width; j++) {
        b0[j] = rand() % 1000;
        b1[j] = rand() % 1000;
        b2[j] = rand() % 1000;
    }
}