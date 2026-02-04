#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *dfdy;
size_t i;

static double dfdy_data[256 * 1024 * 1024 / sizeof(double)]; // ~256 MB to ensure ~0.01 sec runtime

void init_vars() {
    dfdy = dfdy_data;
    i = 0;
}