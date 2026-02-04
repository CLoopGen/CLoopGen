#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *histogram;
size_t hsize;
int x;

void init_vars() {
    hsize = 67108864; // ~256 MB of float data (67M elements * 4 bytes)
    histogram = (float*)aligned_alloc(32, hsize * sizeof(float));
    for (size_t i = 0; i < hsize; i++) {
        histogram[i] = 1.0f;
    }
}