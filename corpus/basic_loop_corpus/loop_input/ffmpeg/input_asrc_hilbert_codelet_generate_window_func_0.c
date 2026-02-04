#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *lut;
int N;
int n;

void init_vars() {
    N = 67108864; // Approximately 256 MB for float array (67M elements)
    lut = (float*)aligned_alloc(32, N * sizeof(float));
    if (!lut) {
        exit(1);
    }
}