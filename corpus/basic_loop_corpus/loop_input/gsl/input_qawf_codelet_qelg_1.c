#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *epstab;
size_t newelm;
size_t i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data to target ~0.01s runtime
    epstab = (double*)aligned_alloc(32, (data_size + 2) * sizeof(double));
    if (!epstab) exit(1);

    for (size_t idx = 0; idx < data_size + 2; idx++) {
        epstab[idx] = (double)(idx & 0xFF);
    }

    newelm = (data_size / 2) - 1;
}