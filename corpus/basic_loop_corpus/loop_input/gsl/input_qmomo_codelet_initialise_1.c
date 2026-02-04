#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *rj;
double beta_p1;
double beta_p2;
double r_beta;
size_t i;
double an;
double anm1;

void init_vars() {
    const size_t data_size = 256 * (1 << 20); // 256 MB
    rj = (double*)aligned_alloc(32, data_size * sizeof(double));
    if (!rj) {
        exit(1);
    }

    beta_p1 = 1.5;
    beta_p2 = 0.5;
    r_beta = 0.25;
    an = 2.0;
    anm1 = 1.0;

    for (size_t idx = 0; idx < 25; ++idx) {
        rj[idx] = 1.0;
    }
}