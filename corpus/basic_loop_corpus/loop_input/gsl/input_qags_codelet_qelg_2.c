#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *epstab;
size_t newelm;
size_t i;

void init_vars() {
    newelm = 131072; // This will make the array size about 2 * (newelm + 2) = 262146 elements
    size_t array_size = (newelm + 3) * 2; // Ensure we access up to index (newelm * 2 + 3)
    epstab = (double*)aligned_alloc(32, array_size * sizeof(double));
    if (!epstab) {
        exit(1);
    }
    for (size_t idx = 0; idx < array_size; idx++) {
        epstab[idx] = (double)(idx);
    }
}