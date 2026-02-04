#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

double h = 1.0;
double *l;
double *hprev;
size_t ord = 20000;
size_t i;
size_t j;
double hsum = 0.0;
double coeff1 = 10.0;
double coeff2 = 0.0;
double hrelprev = 1.0;
double hrelprod = 1.0;
double hrel;

void init_vars() {
    const size_t data_size = ord + 10;
    const size_t total_bytes = data_size * sizeof(double);
    
    l = (double*)aligned_alloc(32, total_bytes);
    hprev = (double*)aligned_alloc(32, total_bytes);
    
    if (!l || !hprev) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (size_t idx = 0; idx < data_size; idx++) {
        l[idx] = 1.0 + idx * 0.001;
        if (idx < ord) {
            hprev[idx] = 0.5 + idx * 0.01;
        }
    }
    
    h = 0.01;
    hsum = 0.0;
    coeff1 = 10.0;
    coeff2 = 0.0;
    hrelprev = 1.0;
    hrelprod = 1.0;
    hrel = 1.0;
    i = 0;
    j = 0;
}