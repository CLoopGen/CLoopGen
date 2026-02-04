#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

float *vec;
int n;
float sum;
int x;

void init_vars() {
    n = 64 * 1024 * 1024; // 64 million elements, ~256 MB for float
    vec = (float*)aligned_alloc(32, n * sizeof(float));
    if (!vec) {
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        vec[i] = 1.0f; // arbitrary value to avoid uninitialized data
    }
    sum = 0.0f;
    x = 0;
}