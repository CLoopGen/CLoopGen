#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *out;
int size;
int i;
int j;
int dim;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 million elements, ~256 MB for float
    dim = 1024;
    out = (float*)aligned_alloc(32, size * sizeof(float));
    if (!out) {
        exit(1);
    }
}