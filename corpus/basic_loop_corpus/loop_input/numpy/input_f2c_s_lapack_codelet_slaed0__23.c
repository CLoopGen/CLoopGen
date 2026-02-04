#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *d__;
real *work;
integer *iwork;
integer i__1;
integer i__;
integer j;
integer indxq;

void init_vars() {
    i__1 = 65536; 
    indxq = 0;

    d__ = (real *)aligned_alloc(32, i__1 * sizeof(real));
    work = (real *)aligned_alloc(32, i__1 * sizeof(real));
    iwork = (integer *)aligned_alloc(32, (indxq + i__1 + 1) * sizeof(integer));

    for (integer idx = 0; idx < i__1; ++idx) {
        d__[idx] = (real)(idx * 1.5f);
        iwork[indxq + idx + 1] = idx;
        work[idx] = 0.0f;
    }
}