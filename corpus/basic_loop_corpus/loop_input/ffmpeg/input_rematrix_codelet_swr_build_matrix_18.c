#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *matrix_param;
int stride;
int i;
int j;
double maxcoef;

void init_vars() {
    stride = 64;
    maxcoef = 2.5;
    matrix_param = (double *)calloc(stride * 64, sizeof(double));
    if (!matrix_param) {
        exit(1);
    }
    for (int idx = 0; idx < stride * 64; idx++) {
        matrix_param[idx] = 1.0 + idx % 100;
    }
}