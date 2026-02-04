#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *beta;
doublereal *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    const size_t data_size = 8192;
    c_dim1 = data_size;
    i__1 = data_size;

    beta = (doublereal*)malloc(sizeof(doublereal));
    *beta = 1.5;

    size_t c_size = (data_size + 1) * (data_size + 1);
    c__ = (doublereal*)calloc(c_size, sizeof(doublereal));

    for (size_t idx = 0; idx < c_size; ++idx) {
        c__[idx] = (doublereal)(idx % 100);
    }
}