#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len;
double alpha;
double *x;
double *y;
int i;

void init_vars() {
    len = 2097152; // ~16.8 MB of data (2 arrays of double, 8 bytes each): 2 * 2M * 8 = 32 MB
    alpha = 1.5;

    x = (double*)aligned_alloc(32, len * sizeof(double));
    y = (double*)aligned_alloc(32, len * sizeof(double));

    for (int j = 0; j < len; j++) {
        x[j] = (double)(j % 100) / 10.0;
        y[j] = (double)(j % 50);
    }
}