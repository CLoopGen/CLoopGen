#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t dim;
double h;
double *z;
size_t i;

void init_vars() {
    dim = 64 * 1024 * 1024 / sizeof(double); // ~512 MB of data to ensure loop takes ~0.01s
    h = 1.5;
    
    z = (double*)aligned_alloc(32, 2 * dim * sizeof(double));
    if (!z) {
        exit(1);
    }
    
    for (size_t idx = 0; idx < 2 * dim; idx++) {
        z[idx] = 1.0;
    }
}