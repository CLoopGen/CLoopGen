#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *out;
float *in;
float *lagged;
int lag;
float fac;
int n;
int k;

void init_vars() {
    n = 65536 * 4; // ~1MB of float data (4 bytes per float)
    lag = 10;
    fac = 0.5f;
    k = lag; // Ensure k starts at a value >= lag to prevent out-of-bounds access in lagged[k - lag]

    in = (float*)aligned_alloc(32, n * sizeof(float));
    out = (float*)aligned_alloc(32, n * sizeof(float));
    lagged = (float*)aligned_alloc(32, n * sizeof(float));

    for (int i = 0; i < n; i++) {
        in[i] = (float)(i % 100) / 100.0f;
        lagged[i] = (float)(i % 50) / 50.0f;
        out[i] = 0.0f;
    }
}