#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m;
BLASLONG n;
float *a;
float *b;
float *c;
BLASLONG ldc;
float aa;
float bb;
int i;
int j;
int k;

void init_vars() {
    // Set dimensions to achieve reasonable workload ~0.01 sec
    // Based on typical modern CPU, aim for moderate problem size
    n = 200;
    m = 250;
    ldc = n + 50; // Ensure ldc >= n to prevent overlap

    // Allocate arrays with appropriate sizes to avoid out-of-bounds access
    a = (float*)aligned_alloc(32, sizeof(float) * m * n);
    b = (float*)aligned_alloc(32, sizeof(float) * n * n);
    c = (float*)aligned_alloc(32, sizeof(float) * m * ldc);

    // Initialize all data to avoid undefined behavior
    for (i = 0; i < m * n; i++) {
        a[i] = 1.0f + (i % 7) * 0.1f;
    }
    for (i = 0; i < n * n; i++) {
        b[i] = 0.5f + (i % 5) * 0.05f;
    }
    for (i = 0; i < m * ldc; i++) {
        c[i] = 2.0f + (i % 11) * 0.01f;
    }

    // Initialize scalars
    aa = 1.0f;
    bb = 1.0f;
}