#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *epstab;
size_t n_orig;
size_t n_final;
size_t i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 MB of data for appropriate timing (~0.01 sec on modern CPU)
    epstab = (double*)aligned_alloc(32, data_size);
    if (!epstab) {
        exit(1);
    }

    n_orig = data_size / sizeof(double) - 1;   // Max index in original array
    n_final = (data_size / sizeof(double)) / 2; // Half the number of elements

    // Ensure that n_orig - n_final + i <= n_orig when i <= n_final
    // => offset access: [n_orig - n_final + i] is valid for i in [0, n_final]
    // So we require n_orig >= n_final, which holds by above assignment

    // Initialize epstab with dummy values to avoid undefined behavior
    for (size_t idx = 0; idx < data_size / sizeof(double); ++idx) {
        epstab[idx] = (double)(idx & 0xFF);
    }
}