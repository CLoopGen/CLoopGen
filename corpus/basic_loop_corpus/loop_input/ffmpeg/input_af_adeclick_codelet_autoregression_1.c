#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int ar_order = 1000;

double *k;
double *r;
double *a;
double alpha = 1.0;
int i;
int j;

void init_vars() {
    k = (double*)calloc(ar_order, sizeof(double));
    r = (double*)calloc(ar_order + 1, sizeof(double));
    a = (double*)calloc(ar_order, sizeof(double));

    for (int idx = 0; idx <= ar_order; idx++) {
        if (idx <= ar_order)
            r[idx] = 1.0 / (1 + idx);
    }

    for (int idx = 0; idx < ar_order; idx++) {
        a[idx] = 0.1;
        k[idx] = 0.0;
    }
}