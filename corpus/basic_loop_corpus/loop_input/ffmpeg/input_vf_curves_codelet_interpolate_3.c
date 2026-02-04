#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
double (*matrix)[3];
double *h;
int n;

void init_vars() {
    n = 20000000; 

    h = (double *)aligned_alloc(32, sizeof(double) * n);
    matrix = (double (*)[3])aligned_alloc(32, sizeof(double) * n * 3);

    for (int idx = 0; idx < n; idx++) {
        h[idx] = (double)(idx + 1);
    }

    for (int idx = 0; idx < n; idx++) {
        matrix[idx][0] = 0.0;
        matrix[idx][1] = 0.0;
        matrix[idx][2] = 0.0;
    }

    i = 1;
}