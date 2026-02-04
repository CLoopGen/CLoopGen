#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *input;
int order;
int size;
double *output;
double scale;
int i;
int j;

void init_vars() {
    size = 1 << 20; // 1 million elements ~8MB of data
    order = 1000;   // Must be <= size to avoid out-of-bounds
    scale = 1.5;

    input = (double*)aligned_alloc(32, size * sizeof(double));
    output = (double*)aligned_alloc(32, (order + 1) * sizeof(double));

    for (int idx = 0; idx < size; idx++) {
        input[idx] = (double)(idx % 100) / 100.0;
    }
    for (int idx = 0; idx <= order; idx++) {
        output[idx] = 0.0;
    }
}