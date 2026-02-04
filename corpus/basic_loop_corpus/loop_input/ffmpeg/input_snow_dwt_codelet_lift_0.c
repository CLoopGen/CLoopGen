#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int DWTELEM;

DWTELEM *dst;
DWTELEM *src;
DWTELEM *ref;
int dst_step;
int src_step;
int ref_step;
int mul;
int add;
int shift;
int inverse;
int w;
int i;

void init_vars() {
    w = 1 << 24; // Approximately 16.7 million iterations to target ~0.01s runtime
    if (w < 1) w = 1;

    dst_step = 1;
    src_step = 1;
    ref_step = 1;
    mul = 3;
    add = 1;
    shift = 2;
    inverse = 0;

    // Allocate arrays with sufficient size, accounting for i+1 access
    dst = (DWTELEM*)aligned_alloc(32, sizeof(DWTELEM) * (w * dst_step + 1));
    src = (DWTELEM*)aligned_alloc(32, sizeof(DWTELEM) * (w * src_step + 1));
    ref = (DWTELEM*)aligned_alloc(32, sizeof(DWTELEM) * ((w + 1) * ref_step + 1));

    // Initialize arrays to avoid undefined behavior
    for (int j = 0; j < w * dst_step + 1; j++) {
        dst[j] = j % 100;
    }
    for (int j = 0; j < w * src_step + 1; j++) {
        src[j] = j % 100;
    }
    for (int j = 0; j < (w + 1) * ref_step + 1; j++) {
        ref[j] = j % 100;
    }

    i = 0;
}