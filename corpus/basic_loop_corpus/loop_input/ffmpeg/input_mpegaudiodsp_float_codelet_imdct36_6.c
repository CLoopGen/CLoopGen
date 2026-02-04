#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float *in;
int j;
float t0;
float t1;
float t2;
float t3;
float tmp[18];
float *tmp1;
float *in1;

static float in_data[1 << 20]; // ~4MB of float data (1M elements)

void init_vars() {
    const int N = 1 << 19; // Ensure in accesses up to index (2*8 + ...) are safe: max offset is 2*8 = 16, so we need at least j + 16*2, j<2 -> size >= 34, but we use large size for timing

    for (int i = 0; i < N; ++i) {
        in_data[i] = (float)(i % 100) * 0.01f;
    }

    in = in_data;
    tmp1 = NULL;
    in1 = NULL;
    j = 0;
    t0 = 0.0f;
    t1 = 0.0f;
    t2 = 0.0f;
    t3 = 0.0f;
    for (int i = 0; i < 18; ++i) {
        tmp[i] = 0.0f;
    }
}