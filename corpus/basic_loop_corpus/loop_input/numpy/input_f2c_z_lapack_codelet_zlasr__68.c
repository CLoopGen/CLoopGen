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
    // Set problem size to achieve ~0.01s runtime
    // Based on typical performance, choose M and I1 to yield sufficient work
    const int M = 8000;           // rows of matrix a
    const int I1 = 8000;          // outer loop bound (j from 2 to I1)
    a_dim1 = M;                   // leading dimension of a
    i__1 = I1;

    // Allocate m as a pointer to integer holding M
    m = (integer*)malloc(sizeof(integer));
    *m = M;

    // Allocate arrays c__ and s of length at least I1
    c__ = (doublereal*)calloc(I1, sizeof(doublereal));
    s = (doublereal*)calloc(I1, sizeof(doublereal));

    // Initialize c__ and s: set c__[j-1] = 1.0 and s[j-1] = 0.0 for most j,
    // but ensure some iterations enter the if-body by making a few nontrivial
    for (int idx = 0; idx < I1; ++idx) {
        c__[idx] = 1.0;
        s[idx] = 0.0;
    }
    // Modify a few values to ensure condition triggers
    if (I1 > 1) {
        c__[1] = 0.8;
        s[1] = 0.6;
    }

    // Allocate matrix a with dimensions [M x I1], stored column-major
    a = (doublecomplex*)calloc(M * I1, sizeof(doublecomplex));
    // Initialize a with non-zero data to make computation meaningful
    for (int col = 0; col < I1; ++col) {
        for (int row = 0; row < M; ++row) {
            int idx = row + col * a_dim1;
            a[idx].r = (doublereal)(row + 1);
            a[idx].i = (doublereal)(col + 1);
        }
    }
}