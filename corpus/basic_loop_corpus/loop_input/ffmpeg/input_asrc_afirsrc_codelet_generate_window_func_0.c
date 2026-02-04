#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *lut;
int N;
int n;

void init_vars() {
    N = 1 << 20; // 1 million elements, ~4MB for float array
    lut = (float*)calloc(N, sizeof(float));
    if (!lut) {
        exit(1);
    }
    n = 0;
}