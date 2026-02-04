#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * 1024 * 1024 / sizeof(float))

float *lsf;
double min_spacing;
int size;
int i;
float prev;

void init_vars() {
    size = ARRAY_SIZE;
    lsf = (float*)aligned_alloc(32, size * sizeof(float));
    if (!lsf) {
        exit(1);
    }

    min_spacing = 0.5;
    prev = 1.0f;

    for (int idx = 0; idx < size; idx++) {
        lsf[idx] = (float)(2.0 * idx / (double)size);
    }
}