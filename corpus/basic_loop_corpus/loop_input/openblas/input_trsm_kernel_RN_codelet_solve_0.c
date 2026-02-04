#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m = 512;
BLASLONG n = 512;
float *a;
float *b;
float *c;
BLASLONG ldc = 512;
float aa;
float bb;
int i;
int j;
int k;

void init_vars() {
    a = (float*)aligned_alloc(32, m * n * sizeof(float));
    b = (float*)aligned_alloc(32, n * n * sizeof(float));
    c = (float*)aligned_alloc(32, m * n * sizeof(float));

    for (int idx = 0; idx < n * n; idx++) {
        b[idx] = 1.0f + (idx % 7) * 0.1f;
    }

    for (int idx = 0; idx < m * n; idx++) {
        c[idx] = 2.0f + (idx % 5) * 0.05f;
        a[idx] = 0.0f;
    }
}