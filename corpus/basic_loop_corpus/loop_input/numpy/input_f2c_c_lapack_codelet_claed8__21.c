#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *d__;
real *z__;
real *dlamda;
real *w;
integer *indxq;
integer i__1;
integer i__;

void init_vars() {
    i__1 = 10000000; // 10 million elements for ~0.01 sec runtime

    d__ = (real*)calloc(i__1 + 1, sizeof(real));
    z__ = (real*)calloc(i__1 + 1, sizeof(real));
    dlamda = (real*)calloc(i__1 + 1, sizeof(real));
    w = (real*)calloc(i__1 + 1, sizeof(real));
    indxq = (integer*)malloc((i__1 + 1) * sizeof(integer));

    for (integer idx = 1; idx <= i__1; ++idx) {
        d__[idx] = (real)(idx * 1.5);
        z__[idx] = (real)(idx * 2.5);
        indxq[idx] = idx; // valid index within bounds
    }
}