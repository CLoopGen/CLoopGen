#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef int integer;

double *out;
double *in;
integer len;
int i;
double coeff;

void init_vars() {
    len = 16777216; // 128 MB of data (16M * 8 bytes per double)

    in = (double*)aligned_alloc(32, len * sizeof(double));
    out = (double*)aligned_alloc(32, len * sizeof(double));

    if (!in || !out) {
        exit(EXIT_FAILURE);
    }

    for (integer idx = 0; idx < len; idx++) {
        in[idx] = (double)(idx % 1000) / 100.0;
    }

    coeff = 2.5;
    i = 0;
}