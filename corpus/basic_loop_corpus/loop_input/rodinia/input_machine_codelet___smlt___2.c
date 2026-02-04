#include <stdlib.h>
#include <stdint.h>

double *dp;
double *out;
double s;
int len;
int i;

void init_vars() {
    len = 16777216; // 128 MB of doubles (16M * 8 bytes per double * 2 arrays ≈ 256 MB total)
    dp = (double*)malloc(len * sizeof(double));
    out = (double*)malloc(len * sizeof(double));
    s = 1.5;
    for (i = 0; i < len; i++) {
        dp[i] = (double)(i % 100) / 10.0;
    }
}