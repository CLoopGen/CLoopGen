#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *z__;
real *beta;
real *vt;
integer vt_dim1;
integer i__1;
integer i__;
integer nlp2;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 million floats (~256MB for z__ and vt combined)
    
    z__ = (real*)aligned_alloc(32, data_size * sizeof(real));
    vt = (real*)aligned_alloc(32, data_size * sizeof(real) * 2); // larger to account for 2D indexing

    beta = (real*)aligned_alloc(32, sizeof(real));
    
    *beta = 1.5f;

    for (size_t i = 0; i < data_size; ++i) {
        z__[i] = 0.0f;
    }
    for (size_t i = 0; i < data_size * 2; ++i) {
        vt[i] = (real)(i % 100) / 100.0f;
    }

    vt_dim1 = (integer)data_size;
    nlp2 = 1;
    i__1 = (integer)(data_size - 1);
    i__ = 0;
}