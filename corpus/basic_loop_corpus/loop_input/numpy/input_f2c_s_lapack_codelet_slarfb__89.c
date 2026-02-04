#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *c__;
real *work;
integer c_dim1;
integer work_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer lastc;

void init_vars() {
    i__1 = 512;
    lastc = 512;
    c_dim1 = 512;
    work_dim1 = 512;

    i__2 = lastc;
    i__ = 0;
    j = 0;

    c__ = (real*)aligned_alloc(64, sizeof(real) * (size_t)(i__1 * c_dim1));
    work = (real*)aligned_alloc(64, sizeof(real) * (size_t)(lastc * work_dim1));

    for (int idx = 0; idx < i__1 * c_dim1; ++idx) {
        c__[idx] = (real)(idx + 1);
    }
    for (int idx = 0; idx < lastc * work_dim1; ++idx) {
        work[idx] = (real)(idx + 1) * 0.5f;
    }
}