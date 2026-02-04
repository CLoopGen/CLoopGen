#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *d__;
real *z__;
real *dsigma;
real *u2;
integer *idx;
integer *idxc;
integer *coltyp;
integer u2_dim1;
integer i__1;
integer i__;
integer idxi;

void init_vars() {
    i__1 = 5000000;  

    u2_dim1 = i__1 + 10;

    d__ = (real*)calloc(i__1 + 1, sizeof(real));
    z__ = (real*)calloc(i__1 + 1, sizeof(real));
    dsigma = (real*)calloc(u2_dim1 + 10, sizeof(real));
    u2 = (real*)calloc((u2_dim1 + 10) * 2, sizeof(real));
    idx = (integer*)malloc((i__1 + 1) * sizeof(integer));
    idxc = (integer*)calloc(u2_dim1 + 10, sizeof(integer));
    coltyp = (integer*)malloc((i__1 + 1) * sizeof(integer));

    for (int i = 2; i <= i__1; ++i) {
        idx[i] = i - 1;
    }

    for (int i = 0; i < u2_dim1 + 10; ++i) {
        dsigma[i] = (real)(i * 1.5);
        idxc[i] = i % 3;
    }

    for (int i = 0; i < (u2_dim1 + 10) * 2; ++i) {
        u2[i] = (real)(i * 0.1);
    }

    i__ = 2;
}