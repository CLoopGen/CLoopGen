#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *ri;
double alpha_p1;
double alpha_p2;
double r_alpha;
size_t i;
double an;
double anm1;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // ~256MB to ensure sufficient runtime
    ri = (double *)aligned_alloc(32, data_size * sizeof(double));
    if (!ri) {
        exit(1);
    }

    alpha_p1 = 1.5;
    alpha_p2 = 0.5;
    r_alpha = 2.0;
    an = 3.0;
    anm1 = 2.0;

    for (size_t idx = 0; idx < data_size; ++idx) {
        ri[idx] = 1.0 + idx * 0.001;
    }
}