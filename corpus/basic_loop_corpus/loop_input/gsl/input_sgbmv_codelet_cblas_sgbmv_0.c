#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *Y;
int incY;
int i;
int lenY;
int iy;

void init_vars() {
    lenY = 65536 * 4;  // ~256KB of float data (65536*4*4 = 1MB)
    incY = 1;
    iy = 0;

    Y = (float*)aligned_alloc(32, lenY * sizeof(float));
    if (!Y) {
        exit(1);
    }
}