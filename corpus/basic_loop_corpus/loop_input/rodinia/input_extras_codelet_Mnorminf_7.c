#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int len;
double *x;
int i;
double tmp;
double max_val;

void init_vars() {
    len = 25000000; // Approximately 200MB of data (25M * 8 bytes per double)
    x = (double*)aligned_alloc(32, len * sizeof(double));
    if (!x) {
        exit(1);
    }

    for (int j = 0; j < len; j++) {
        x[j] = drand48() * 200.0 - 100.0;
    }

    i = 0;
    tmp = 0.0;
    max_val = 0.0;
}