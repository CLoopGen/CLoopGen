#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *k;
doublecomplex *c__;
doublecomplex *work;
integer c_dim1;
integer work_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
doublecomplex z__1;
integer i__;
integer j;
integer lastc;
integer lastv;

static integer k_storage = 10;
static integer c_rows = 2000;
static integer c_cols = 2000;
static integer work_rows = 2000;
static integer work_cols = 2000;

void init_vars() {
    k = &k_storage;
    c_dim1 = c_rows;
    work_dim1 = work_rows;
    i__1 = 150; 
    lastc = c_rows;
    lastv = 1800;

    c__ = (doublecomplex*)calloc((size_t)(c_rows * c_cols), sizeof(doublecomplex));
    work = (doublecomplex*)calloc((size_t)(work_rows * work_cols), sizeof(doublecomplex));

    if (c__ == NULL || work == NULL) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (integer idx = 0; idx < c_rows * c_cols; ++idx) {
        c__[idx].r = (doublereal)(idx % 100) / 10.0;
        c__[idx].i = (doublereal)(idx % 101) / 11.0;
    }
    for (integer idx = 0; idx < work_rows * work_cols; ++idx) {
        work[idx].r = (doublereal)(idx % 99) / 9.0;
        work[idx].i = (doublereal)(idx % 97) / 7.0;
    }

    i__ = 0;
    j = 0;
    z__1.r = 0.0;
    z__1.i = 0.0;
}