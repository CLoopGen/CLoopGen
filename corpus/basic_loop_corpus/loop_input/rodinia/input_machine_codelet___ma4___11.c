#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

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
double w0;

void init_vars() {
    len = 16777216;  // 16M * sizeof(double) = 128MB total for arrays

    v0 = (double*)aligned_alloc(32, len * sizeof(double));
    v1 = (double*)aligned_alloc(32, len * sizeof(double));
    v2 = (double*)aligned_alloc(32, len * sizeof(double));
    v3 = (double*)aligned_alloc(32, len * sizeof(double));
    w  = (double*)aligned_alloc(32, len * sizeof(double));

    for (int j = 0; j < len; j++) {
        v0[j] = 1.0;
        v1[j] = 1.0;
        v2[j] = 1.0;
        v3[j] = 1.0;
        w[j]  = 2.0;
    }

    a0 = 0.5;
    a1 = 0.6;
    a2 = 0.7;
    a3 = 0.8;
}