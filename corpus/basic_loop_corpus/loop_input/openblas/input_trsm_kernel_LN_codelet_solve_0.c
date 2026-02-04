#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    a = (float*)aligned_alloc(32, sizeof(float) * m * m);
    b = (float*)aligned_alloc(32, sizeof(float) * m * n);
    c = (float*)aligned_alloc(32, sizeof(float) * m * n);

    for (int idx = 0; idx < m * m; idx++) {
        a[idx] = 1.0f + (idx % 7);
    }
    for (int idx = 0; idx < m * n; idx++) {
        b[idx] = 1.0f + (idx % 5);
        c[idx] = 2.0f + (idx % 3);
    }
}