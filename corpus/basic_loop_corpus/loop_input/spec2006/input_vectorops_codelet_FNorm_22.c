#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

float *vec;
int n;
int x;
float sum;

void init_vars() {
    n = 1 << 20; // 1 million elements, approximately 4MB of data
    vec = (float *)aligned_alloc(32, n * sizeof(float));
    sum = 123.45f;
    for (int i = 0; i < n; i++) {
        vec[i] = (float)(i + 1) * 0.5f;
    }
    x = 0;
}