#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

double qq = 3.14159;
unsigned int odd_order;
unsigned int ii;
unsigned int jj;
double *zz;

void init_vars() {
    odd_order = 8000; 
    size_t total_size = (size_t)odd_order * odd_order * sizeof(double);
    zz = aligned_alloc(32, total_size);
    if (!zz) {
        exit(1);
    }
    for (size_t i = 0; i < total_size / sizeof(double); i++) {
        zz[i] = 0.0;
    }
}