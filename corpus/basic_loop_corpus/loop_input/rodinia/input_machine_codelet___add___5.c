#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *dp1;
double *dp2;
double *out;
int len;
int i;

static double *dp1_buf;
static double *dp2_buf;
static double *out_buf;

void init_vars() {
    len = 32000000; // Approximately 256MB of data (3 arrays * 8 bytes per double * 32e6 ≈ 768MB), loop time ~0.01s on modern CPU

    dp1_buf = (double *)aligned_alloc(32, len * sizeof(double));
    dp2_buf = (double *)aligned_alloc(32, len * sizeof(double));
    out_buf = (double *)aligned_alloc(32, len * sizeof(double));

    if (!dp1_buf || !dp2_buf || !out_buf) {
        exit(1);
    }

    for (int j = 0; j < len; j++) {
        dp1_buf[j] = (double)(j % 1000) / 3.0;
        dp2_buf[j] = (double)(j % 1500) / 7.0;
    }

    dp1 = dp1_buf;
    dp2 = dp2_buf;
    out = out_buf;
}