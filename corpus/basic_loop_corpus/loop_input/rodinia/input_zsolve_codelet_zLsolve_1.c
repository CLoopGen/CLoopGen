#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double re;
    double im;
} complex;

u_int dim = 4194304; // ~64MB of data (each complex is 16 bytes), suitable for ~0.01s runtime
u_int i = 0;
complex *b_ent;
complex *out_ent;

void init_vars() {
    b_ent = (complex*)aligned_alloc(32, dim * sizeof(complex));
    out_ent = (complex*)aligned_alloc(32, dim * sizeof(complex));

    if (!b_ent || !out_ent) {
        exit(1);
    }

    for (u_int idx = 0; idx < dim; idx++) {
        b_ent[idx].re = 0.0;
        b_ent[idx].im = 0.0;
        out_ent[idx].re = 1.0;
        out_ent[idx].im = 1.0;
    }

    b_ent[dim - 1].re = 1.0;
}