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

integer *n;
doublereal *c__;
doublereal *s;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
doublecomplex z__1;
doublecomplex z__2;
doublecomplex z__3;
integer i__;
integer j;
doublecomplex temp;
doublereal ctemp;
doublereal stemp;

void init_vars() {
    // Set problem size to control runtime (~0.01 seconds)
    // Based on typical performance, choose n ≈ 5000-10000 and i__1 ≈ 5000 for reasonable FLOPs
    const int N_VAL = 8192;        // Size of vectors and matrix columns
    const int I1_VAL = 8192;       // Outer loop bound (j from 1 to i__1)

    // Allocate memory
    n = (integer*)malloc(sizeof(integer));
    c__ = (doublereal*)calloc(N_VAL + 1, sizeof(doublereal)); // 1-indexed: index 1..N_VAL
    s = (doublereal*)calloc(N_VAL + 1, sizeof(doublereal));
    a = (doublecomplex*)calloc((N_VAL + 1) * (N_VAL + 1), sizeof(doublecomplex)); // 2D-like array

    // Initialize values
    *n = N_VAL;
    i__1 = I1_VAL;
    a_dim1 = N_VAL + 1;  // leading dimension for matrix 'a'

    // Ensure we don't exceed allocated bounds in loops
    if (I1_VAL >= N_VAL) {
        i__1 = N_VAL - 1;  // so that j+1 <= N_VAL when accessing a[j+1 + i*a_dim1]
    }

    // Initialize c__ and s arrays: make most non-trivial (not 1.0/0.0) to enter the branch
    for (int idx = 1; idx <= i__1; ++idx) {
        c__[idx] = 0.8;
        s[idx] = 0.6;
    }

    // Initialize matrix a with non-zero values
    for (int i = 1; i <= N_VAL; ++i) {
        for (int j = 1; j <= N_VAL; ++j) {
            int idx = j + i * a_dim1;
            a[idx].r = (doublereal)(i % 100) * 0.01;
            a[idx].i = (doublereal)(j % 100) * 0.01;
        }
    }

    // Initialize temporaries to zero
    temp.r = 0.0; temp.i = 0.0;
    ctemp = 0.0;
    stemp = 0.0;
    z__1.r = 0.0; z__1.i = 0.0;
    z__2.r = 0.0; z__2.i = 0.0;
    z__3.r = 0.0; z__3.i = 0.0;
    i__ = 0;
    j = 0;
}