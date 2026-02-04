#include <stdlib.h>
#include <stdio.h>

double *epstab;
size_t n_orig;
size_t n_final;
size_t i;

void init_vars() {
    n_final = 1000000; // ensures loop runs ~1M iterations
    n_orig = 2 * n_final; // ensure n_orig >= n_final

    epstab = (double*)aligned_alloc(32, (n_orig + n_final + 1) * sizeof(double));
    if (!epstab) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}

// The loop function is defined externally and uses the above variables