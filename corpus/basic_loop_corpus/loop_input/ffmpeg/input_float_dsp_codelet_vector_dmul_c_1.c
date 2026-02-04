#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *dst;
double *src0;
double *src1;
int len;
int i;

void init_vars() {
    len = 32 * 1024 * 1024 / sizeof(double); // ~256 MB total data (dst, src0, src1: 3 arrays)
    size_t bytes = len * sizeof(double);

    dst = (double*)aligned_alloc(32, bytes);
    src0 = (double*)aligned_alloc(32, bytes);
    src1 = (double*)aligned_alloc(32, bytes);

    for (int j = 0; j < len; j++) {
        src0[j] = 1.0 + j * 0.000001;
        src1[j] = 2.0 - j * 0.000001;
    }
}