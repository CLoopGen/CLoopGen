#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *lut;
int N = 1 << 20;  // Approximately 4MB of float data (1M elements), suitable for ~0.01s runtime
int n;

void init_vars() {
    lut = (float*)aligned_alloc(32, N * sizeof(float));
    if (!lut) {
        exit(1);
    }
}