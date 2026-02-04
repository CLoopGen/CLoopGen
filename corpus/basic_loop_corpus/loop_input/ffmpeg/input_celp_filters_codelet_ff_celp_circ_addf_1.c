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
    n = 1 << 20; // 1 million elements, approximately 4MB per array
    lag = 10000; // Ensure lag is less than or equal to n to prevent out-of-bounds access
    fac = 1.5f;

    in = (float*)aligned_alloc(32, n * sizeof(float));
    out = (float*)aligned_alloc(32, n * sizeof(float));
    lagged = (float*)aligned_alloc(32, (n + lag) * sizeof(float)); // Ensure enough space for n + k - lag

    for (int i = 0; i < n; i++) {
        in[i] = (float)(rand() % 100) / 10.0f;
        out[i] = 0.0f;
    }
    for (int i = 0; i < n + lag; i++) {
        lagged[i] = (float)(rand() % 100) / 10.0f;
    }
}