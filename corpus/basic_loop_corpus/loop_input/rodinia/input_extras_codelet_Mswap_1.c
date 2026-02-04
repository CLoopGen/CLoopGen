#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int len;
double *x;
double *y;
int i;
double tmp;

void init_vars() {
    len = 10000000;  // Approximately 80 MB of data (10M * 8 bytes per double * 2 arrays)

    x = (double *)aligned_alloc(32, len * sizeof(double));
    y = (double *)aligned_alloc(32, len * sizeof(double));

    if (!x || !y) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < len; j++) {
        x[j] = (double)(j % 1000) + 0.1;
        y[j] = (double)((j + 500) % 1000) + 0.2;
    }
}