#include <stdlib.h>
#include <stdio.h>

double *dp1;
double *dp2;
double *out;
int len;
int i;

void init_vars() {
    len = 32000000; // Approximately 256MB of input data (3 arrays * 8 bytes * 32e6 ≈ 768MB total)
    dp1 = (double*)aligned_alloc(32, len * sizeof(double));
    dp2 = (double*)aligned_alloc(32, len * sizeof(double));
    out = (double*)aligned_alloc(32, len * sizeof(double));

    for (i = 0; i < len; i++) {
        dp1[i] = (double)(i % 1000) / 10.0;
        dp2[i] = (double)((i + 500) % 1000) / 10.0;
    }
}