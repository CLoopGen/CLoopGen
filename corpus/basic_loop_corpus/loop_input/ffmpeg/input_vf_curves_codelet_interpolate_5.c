#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
double (*matrix)[3];
double *r;
int n;

void init_vars() {
    n = 10000000;  // Adjusted size for ~0.01 sec runtime on modern CPU

    matrix = (double (*)[3])calloc(n, sizeof(*matrix));
    r = (double *)calloc(n, sizeof(*r));

    if (!matrix || !r) {
        exit(1);
    }

    for (int idx = 0; idx < n; ++idx) {
        matrix[idx][2] = 1.0;
        r[idx] = 1.0;
    }
}