#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double h = 1.5;
size_t ord = 8000;
size_t i = 0;
size_t j = 0;
double hsum = 0.0;

double *l;
double *hprev;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of data
    l = (double *)calloc(data_size, sizeof(double));
    hprev = (double *)calloc(data_size, sizeof(double));

    for (size_t idx = 0; idx < data_size; idx++) {
        l[idx] = (double)(idx % 100) + 1.0;
        hprev[idx] = (double)(idx % 50) + 0.5;
    }

    h = 1.5;
    hsum = 0.0;
    ord = 8000; 
}