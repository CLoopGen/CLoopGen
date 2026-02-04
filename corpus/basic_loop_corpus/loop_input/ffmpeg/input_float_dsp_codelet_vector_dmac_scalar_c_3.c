#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *dst;
double *src;
double mul;
int len;
int i;

void init_vars() {
    len = 16777216; // 128 MB of data (16M * 8 bytes per double)
    mul = 2.5;

    src = (double *)aligned_alloc(32, len * sizeof(double));
    dst = (double *)aligned_alloc(32, len * sizeof(double));

    for (int j = 0; j < len; j++) {
        src[j] = (double)(j % 1000) / 100.0;
        dst[j] = (double)(j % 500) / 200.0;
    }
}