#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

double *dp1;
double *dp2;
double *out;
int len;
int i;

void init_vars() {
    // Target approximately 0.01 seconds runtime on modern CPU
    // Estimate: ~1e8 operations at a few cycles each -> ~1e7 to 1e8 doubles
    // Use 4 million doubles (32 MB total for 3 arrays) as a reasonable size
    len = 4000000;

    dp1 = (double*)aligned_alloc(32, len * sizeof(double));
    dp2 = (double*)aligned_alloc(32, len * sizeof(double));
    out = (double*)aligned_alloc(32, len * sizeof(double));

    if (!dp1 || !dp2 || !out) {
        exit(1);
    }

    for (int j = 0; j < len; j++) {
        dp1[j] = (double)(j % 1000) / 100.0;
        dp2[j] = (double)((j + 50) % 1000) / 100.0;
    }
}