#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *r;
double *cheb12;
size_t i;
double res12;

static double r_data[13];
static double cheb12_data[13];

void init_vars() {
    r = r_data;
    cheb12 = cheb12_data;
    i = 0;
    res12 = 0.0;

    for (size_t idx = 0; idx < 13; idx++) {
        r[idx] = 1.0 + idx * 0.1;
        cheb12[idx] = 0.5 - idx * 0.05;
    }
}