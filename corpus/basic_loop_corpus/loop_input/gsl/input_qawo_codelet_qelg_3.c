#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *epstab;
size_t newelm;
size_t i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime (~0.01 sec)
    newelm = (data_size / sizeof(double)) / 2 - 1; // Ensure epstab[i*2+2] is in bounds

    epstab = (double*)aligned_alloc(32, (newelm + 2) * 2 * sizeof(double));
    if (!epstab) exit(1);

    for (size_t idx = 0; idx < (newelm + 2) * 2; ++idx) {
        epstab[idx] = (double)(idx & 511);
    }
}