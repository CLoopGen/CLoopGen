#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *dp1;
double *dp2;
double *out;
int len;
int i;

static double *dp1_storage;
static double *dp2_storage;
static double *out_storage;

void init_vars() {
    len = 32000000; // Approximately 256MB of data (3 arrays * 8 bytes per double * 32e6 elements)

    dp1_storage = (double*)aligned_alloc(32, len * sizeof(double));
    dp2_storage = (double*)aligned_alloc(32, len * sizeof(double));
    out_storage = (double*)aligned_alloc(32, len * sizeof(double));

    if (!dp1_storage || !dp2_storage || !out_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dp1 = dp1_storage;
    dp2 = dp2_storage;
    out = out_storage;

    for (i = 0; i < len; i++) {
        dp1_storage[i] = (double)(i + 1) * 1.5;
        dp2_storage[i] = (double)(i + 1) * 0.5;
    }
}