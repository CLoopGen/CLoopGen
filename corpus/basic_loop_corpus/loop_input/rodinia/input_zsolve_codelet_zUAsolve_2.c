#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double re;
    double im;
} complex;

u_int dim = 4194304; // ~64MB of data (each complex is 16 bytes), chosen to run loop for ~0.01s
u_int i = 0;
complex *b_ve;
complex *out_ve;

void init_vars() {
    b_ve = (complex*)aligned_alloc(32, dim * sizeof(complex));
    out_ve = (complex*)aligned_alloc(32, dim * sizeof(complex));

    for (u_int idx = 0; idx < dim; idx++) {
        if (idx < dim - 1) {
            b_ve[idx].re = 0.0;
            b_ve[idx].im = 0.0;
        } else {
            b_ve[idx].re = 1.0;
            b_ve[idx].im = 1.0;
        }
        out_ve[idx].re = 1.0;
        out_ve[idx].im = 1.0;
    }
}