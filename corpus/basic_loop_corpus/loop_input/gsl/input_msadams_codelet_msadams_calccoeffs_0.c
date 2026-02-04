#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t ord = 1000;
size_t ordwait = 1;
double h = 1.0e-3;
double *ordm1coeff;
double pc[1000];
size_t i;
size_t j;
double hsum;

double hprev[999];

void init_vars() {
    ord = 1000;
    ordwait = 1;
    h = 1.0e-3;
    hsum = 1.0;

    for (i = 0; i < ord; i++) {
        pc[i] = 1.0 / (i + 1);
    }

    for (i = 0; i < ord - 1; i++) {
        hprev[i] = h * (0.5 + (i % 7) * 0.1);
    }

    ordm1coeff = (double*)malloc(sizeof(double));
    *ordm1coeff = 1.0;
}