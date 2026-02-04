#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double V2inv[81];
double *fx;
double *c;
int i;
int j;

void init_vars() {
    fx = (double *)aligned_alloc(32, 9 * 4 * sizeof(double));
    c = (double *)aligned_alloc(32, 9 * sizeof(double));

    for (int idx = 0; idx < 81; idx++) {
        V2inv[idx] = 1.0 / (idx + 1);
    }

    for (int idx = 0; idx < 9 * 4; idx++) {
        fx[idx] = idx * 0.5;
    }

    for (int idx = 0; idx < 9; idx++) {
        c[idx] = 0.0;
    }
}