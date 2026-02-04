#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float *lut;
int N;
int n;

void init_vars() {
    N = 1 << 20;  // Approximately 4 million elements for ~0.01 sec runtime
    lut = (float*)aligned_alloc(32, N * sizeof(float));
    if (!lut) {
        exit(1);
    }
}

__attribute__((destructor))
static void cleanup() {
    if (lut) {
        free(lut);
    }
}