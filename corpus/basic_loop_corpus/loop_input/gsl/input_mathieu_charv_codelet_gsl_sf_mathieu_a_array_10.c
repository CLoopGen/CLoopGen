#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int even_order;
unsigned int ii;

double *dd;
double *ee;
double *zz;

void init_vars() {
    even_order = 8192;  

    dd = (double *)aligned_alloc(32, even_order * sizeof(double));
    ee = (double *)aligned_alloc(32, even_order * sizeof(double));
    zz = (double *)aligned_alloc(32, even_order * even_order * sizeof(double));

    for (unsigned int i = 0; i < even_order; i++) {
        dd[i] = 1.1 * i;
        ee[i] = 2.2 * i;
    }

    for (unsigned int i = 0; i < even_order * even_order; i++) {
        zz[i] = 0.0;
    }
}