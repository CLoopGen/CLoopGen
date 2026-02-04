#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *v;
int len;
int k;

void init_vars() {
    len = 64 * 1024 * 1024 / sizeof(float);  // ~256MB of data to ensure loop runtime around 0.01s
    v = (float*)aligned_alloc(32, len * sizeof(float));
    if (!v) {
        exit(1);
    }
    for (int i = 0; i < len; ++i) {
        v[i] = (float)(i % 1000) + 1.0f;
    }
    k = 0;
}