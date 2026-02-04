#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
singlecomplex *c__;
real *rwork;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;
integer l;

void init_vars() {
    const size_t data_size_mb = 64;
    const size_t total_elements = (data_size_mb * (1 << 20)) / sizeof(real);

    rwork = (real*)aligned_alloc(32, total_elements * sizeof(real));
    c__ = (singlecomplex*)aligned_alloc(32, total_elements * sizeof(singlecomplex));

    for (size_t idx = 0; idx < total_elements; ++idx) {
        rwork[idx] = (real)(idx % 256);
        c__[idx].r = 0.0f;
        c__[idx].i = 0.0f;
    }

    m = (integer*)aligned_alloc(32, sizeof(integer));
    *m = (integer)(total_elements / 8);
    l = 1;
    c_dim1 = *m;
    i__1 = (integer)(total_elements / (*m));
}