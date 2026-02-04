#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *epstab;
size_t newelm;
size_t i;

void init_vars() {
    newelm = 131072; // Size to achieve ~0.01s runtime with ~1MB data
    size_t array_size = (newelm + 1) * 2 + 3;
    epstab = (double*)aligned_alloc(32, array_size * sizeof(double));
    for (size_t idx = 0; idx < array_size; idx++) {
        epstab[idx] = (double)(idx & 511);
    }
}