#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *z__;
doublereal *vf;
doublereal *beta;
integer i__1;
integer i__;
integer nlp2;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of total data (adjustable)

    z__ = (doublereal*)aligned_alloc(32, data_size * sizeof(doublereal));
    vf = (doublereal*)aligned_alloc(32, data_size * sizeof(doublereal));
    beta = (doublereal*)aligned_alloc(32, sizeof(doublereal));

    if (!z__ || !vf || !beta) {
        exit(1);
    }

    *beta = 2.5;

    for (size_t i = 0; i < data_size; ++i) {
        z__[i] = 0.0;
        vf[i] = 1.0;
    }

    nlp2 = 0;
    i__1 = data_size - 1;
}