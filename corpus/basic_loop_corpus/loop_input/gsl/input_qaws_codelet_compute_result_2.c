#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *r;
double *cheb24;
size_t i;
double res24;

static double r_data[25];
static double cheb24_data[25];

void init_vars() {
    r = r_data;
    cheb24 = cheb24_data;
    i = 0;
    res24 = 0.0;

    for (size_t idx = 0; idx < 25; idx++) {
        r_data[idx] = 1.0 + idx * 0.1;
        cheb24_data[idx] = 0.5 - idx * 0.02;
    }
}