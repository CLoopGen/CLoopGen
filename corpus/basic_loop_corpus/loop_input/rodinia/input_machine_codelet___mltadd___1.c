#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

double *dp1;
double *dp2;
double s;
int len;
int i;

void init_vars() {
    len = 16777216; // 128 MB of data (16M * 8 bytes per double)
    dp1 = (double *)aligned_alloc(32, len * sizeof(double));
    dp2 = (double *)aligned_alloc(32, len * sizeof(double));

    if (!dp1 || !dp2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < len; j++) {
        dp1[j] = (double)(j % 1000) / 10.0;
        dp2[j] = (double)((j + 5) % 1000) / 15.0;
    }

    s = 1.2345;
    i = 0;
}