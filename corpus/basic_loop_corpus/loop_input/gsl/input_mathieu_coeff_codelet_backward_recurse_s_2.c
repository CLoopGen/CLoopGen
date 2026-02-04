#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double aa = 1.5;
double qq = 2.5;

int ni = 1000000;  // Approximately tuned for ~0.01 sec runtime
int ii;
int nn;

double *ff;

void init_vars() {
    ff = (double *)aligned_alloc(32, (ni + 1) * sizeof(double));
    if (!ff) {
        exit(1);
    }

    for (int i = 0; i <= ni; i++) {
        ff[i] = 1.0 / (i + 1);
    }
}