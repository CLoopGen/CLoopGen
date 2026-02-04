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

integer *m;
doublecomplex *alpha;
doublecomplex *x;
doublecomplex *y;
integer *incy;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
doublecomplex z__1;
doublecomplex z__2;
integer i__;
integer j;
integer jy;
doublecomplex temp;

void init_vars() {
    // Allocate and initialize scalar parameters
    m = (integer*)malloc(sizeof(integer));
    *m = 1000;  // Size of inner loop

    incy = (integer*)malloc(sizeof(integer));
    *incy = 1;

    alpha = (doublecomplex*)malloc(sizeof(doublecomplex));
    alpha->r = 1.0;
    alpha->i = 0.5;

    i__1 = 256;  // Outer loop count

    a_dim1 = *m;  // Leading dimension of matrix 'a'

    // Allocate arrays
    x = (doublecomplex*)calloc(*m, sizeof(doublecomplex));
    y = (doublecomplex*)calloc(i__1 + (*incy) * (i__1 - 1) + 1, sizeof(doublecomplex));
    a = (doublecomplex*)calloc((*m) * (i__1 + 1), sizeof(doublecomplex));  // Extra space for safety

    // Initialize x with non-zero values
    for (int idx = 0; idx < *m; ++idx) {
        x[idx].r = (doublereal)(idx % 7) / 7.0;
        x[idx].i = (doublereal)(idx % 11) / 11.0;
    }

    // Initialize y with mixed zero and non-zero to trigger the condition
    for (int idx = 0; idx < i__1; ++idx) {
        if (idx % 3 != 0) {
            y[idx * (*incy)].r = (doublereal)(idx % 13) / 13.0;
            y[idx * (*incy)].i = (doublereal)(idx % 17) / 17.0;
        } else {
            y[idx * (*incy)].r = 0.0;
            y[idx * (*incy)].i = 0.0;
        }
    }

    // Initialize a matrix (partially used)
    for (int j = 0; j <= i__1; ++j) {
        for (int i = 0; i < *m; ++i) {
            a[i + j * a_dim1].r = (doublereal)(i * j % 19) / 19.0;
            a[i + j * a_dim1].i = (doublereal)(i * j % 23) / 23.0;
        }
    }

    // Initialize temporary variables to zero
    temp.r = 0.0;
    temp.i = 0.0;
    z__1.r = 0.0;
    z__1.i = 0.0;
    z__2.r = 0.0;
    z__2.i = 0.0;

    // Initialize loop indices
    i__ = 0;
    j = 0;
    jy = 0;  // Will be incremented in loop; ensure initial access is valid
}