#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

int len;
double alpha;
double *x;
int i;

void init_vars() {
    len = 16777216; // 16M elements, ~128MB for double array
    alpha = 1.5;
    x = (double*)aligned_alloc(32, len * sizeof(double));
    if (!x) {
        exit(1);
    }
    for (i = 0; i < len; i++) {
        x[i] = (double)(i % 1000) / 100.0;
    }
}