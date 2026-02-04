#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double V4inv[1089];
double *fx;
double *c;
int i;
int j;

void init_vars() {
    fx = (double*)malloc(33 * sizeof(double));
    c = (double*)malloc(33 * sizeof(double));

    for (int idx = 0; idx < 33; idx++) {
        fx[idx] = 1.0;
    }

    for (int idx = 0; idx < 1089; idx++) {
        V4inv[idx] = 1.0 / (idx + 1);
    }
}