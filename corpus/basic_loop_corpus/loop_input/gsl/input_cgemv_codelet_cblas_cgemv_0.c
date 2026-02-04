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
    const size_t total_size = 64 * 1024 * 1024; // ~64 MB for sufficient runtime (~0.01 sec)
    Y = (float*)aligned_alloc(32, total_size);
    if (!Y) exit(1);

    incY = 1;
    lenY = total_size / (2 * sizeof(float));
    iy = 0;
}