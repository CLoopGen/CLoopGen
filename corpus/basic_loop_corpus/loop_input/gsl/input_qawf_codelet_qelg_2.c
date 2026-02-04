#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *epstab;
size_t n_orig;
size_t n_final;
size_t i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime
    epstab = (double*)aligned_alloc(32, data_size);
    if (!epstab) {
        exit(1);
    }

    n_orig = 16 * 1024 * 1024; // 16M elements offset
    n_final = 8 * 1024 * 1024; // 8M elements to copy

    // Ensure n_orig - n_final + n_final <= allocated size
    // i.e., n_orig <= data_size / sizeof(double)
    if (n_orig + n_final > data_size / sizeof(double)) {
        n_orig = (data_size / sizeof(double)) / 2;
        n_final = n_orig;
    }

    for (size_t idx = 0; idx < data_size / sizeof(double); ++idx) {
        epstab[idx] = (double)(idx & 0xFF);
    }
}