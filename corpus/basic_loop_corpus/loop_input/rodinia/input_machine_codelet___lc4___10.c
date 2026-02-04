#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *v0;
double *v1;
double *v2;
double *v3;
double *w;
int len;
int i;
double a0;
double a1;
double a2;
double a3;

void init_vars() {
    len = 16777216; // 16M elements, ~128 MB of data (64 bytes per element * 4 vectors + w), targets ~0.01s runtime

    v0 = (double*)aligned_alloc(32, len * sizeof(double));
    v1 = (double*)aligned_alloc(32, len * sizeof(double));
    v2 = (double*)aligned_alloc(32, len * sizeof(double));
    v3 = (double*)aligned_alloc(32, len * sizeof(double));
    w  = (double*)aligned_alloc(32, len * sizeof(double));

    a0 = 1.5;
    a1 = 2.0;
    a2 = -1.0;
    a3 = 0.5;

    for (int j = 0; j < len; j++) {
        v0[j] = (double)(j % 128) / 128.0;
        v1[j] = (double)(j % 64) / 64.0;
        v2[j] = (double)(j % 32) / 32.0;
        v3[j] = (double)(j % 16) / 16.0;
        w[j]  = (double)j / len;
    }
}