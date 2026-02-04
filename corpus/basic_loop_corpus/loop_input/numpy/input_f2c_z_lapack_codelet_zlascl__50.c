#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *m;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
doublecomplex z__1;
integer i__;
integer j;
doublereal mul;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Empirical tuning: use matrix of size ~8000x8000 for sufficient work
    const int n = 8192;

    // Allocate and initialize m (size of matrix dimension)
    m = (integer*)malloc(sizeof(integer));
    *m = n;

    // Allocate the 2D array 'a' as a column-major matrix of size (*m) x (*m)
    a_dim1 = *m;  // leading dimension
    a = (doublecomplex*)calloc(a_dim1 * (*m), sizeof(doublecomplex));

    // Initialize loop bound i__1 to be about half the matrix size to limit total work
    i__1 = n / 2;

    // Initialize mul to a non-zero value
    mul = 2.5;

    // Ensure all temporary indices are initialized (will be overwritten in loop, but safe)
    i__ = 0;
    j = 0;
    i__2 = 0;
    i__3 = 0;
    i__4 = 0;
    z__1.r = 0.0;
    z__1.i = 0.0;

    // Initialize a portion of the matrix to non-zero values to make scaling observable
    for (int col = 1; col <= i__1; ++col) {
        int row_bound = (col + 1 <= *m) ? (col + 1) : *m;
        for (int row = 1; row <= row_bound; ++row) {
            int idx = row + col * a_dim1;
            if (idx < a_dim1 * (*m)) {
                a[idx].r = 1.0 + row * 0.01;
                a[idx].i = 0.5 + col * 0.01;
            }
        }
    }
}