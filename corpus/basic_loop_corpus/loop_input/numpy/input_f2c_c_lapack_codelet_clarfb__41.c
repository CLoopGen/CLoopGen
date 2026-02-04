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

integer *k;
singlecomplex *c__;
singlecomplex *work;
integer c_dim1;
integer work_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
singlecomplex q__1;
integer i__;
integer j;
integer lastc;
integer lastv;

void init_vars() {
    const integer k_val = 100;
    k = (integer*)malloc(sizeof(integer));
    *k = k_val;

    lastv = 2000;
    lastc = 512;
    i__1 = 128;

    c_dim1 = lastc;
    work_dim1 = lastc;

    integer c_size = lastc * (lastv - *k + i__1) + lastc;
    if (c_size <= 0) c_size = lastc * lastv;
    c__ = (singlecomplex*)calloc(c_size, sizeof(singlecomplex));

    integer work_size = lastc * i__1 + lastc;
    work = (singlecomplex*)calloc(work_size, sizeof(singlecomplex));

    for (integer idx = 0; idx < c_size; ++idx) {
        c__[idx].r = (real)(idx % 128) / 64.0f;
        c__[idx].i = (real)(idx % 64) / 32.0f;
    }

    for (integer idx = 0; idx < work_size; ++idx) {
        work[idx].r = (real)(idx % 97) / 48.0f;
        work[idx].i = (real)(idx % 53) / 24.0f;
    }
}