#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double V3inv[289];
double *fx;
double *c;
int i;
int j;

void init_vars() {
    fx = (double*)aligned_alloc(32, sizeof(double) * 34);
    c = (double*)aligned_alloc(32, sizeof(double) * 17);

    for (int idx = 0; idx < 289; idx++) {
        V3inv[idx] = 1.0 / (1.0 + idx);
    }

    for (int idx = 0; idx < 34; idx++) {
        fx[idx] = (double)(idx * 2);
    }

    for (int idx = 0; idx < 17; idx++) {
        c[idx] = 0.0;
    }
}