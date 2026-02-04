#include <stdlib.h>
#include <stddef.h>

double *epstab;
size_t n_orig;
size_t n_final;
size_t i;

void init_vars() {
    n_orig = 100000000; // 100 million elements
    n_final = 50000000; // 50 million elements
    epstab = (double*)aligned_alloc(32, (n_orig + n_final) * sizeof(double));
    
    for (size_t idx = 0; idx < n_orig + n_final; idx++) {
        epstab[idx] = (double)(idx);
    }
}

void loop();