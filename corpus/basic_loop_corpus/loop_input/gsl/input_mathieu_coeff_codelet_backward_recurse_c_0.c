#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double aa = 2.0;
double qq = 1.5;
int ni = 1000000;
int ii;
int nn;
double *ff;

void init_vars() {
    ff = (double*)aligned_alloc(32, (ni + 1) * sizeof(double));
    if (!ff) {
        exit(1);
    }
    for (int i = 0; i <= ni; i++) {
        ff[i] = 1.0 + 0.01 * i;
    }
    aa = 2.0;
    qq = 1.5;
    ni = 1000000;
}