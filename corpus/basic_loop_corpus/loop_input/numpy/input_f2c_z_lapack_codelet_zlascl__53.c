#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

doublecomplex *a = NULL;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
doublecomplex z__1;
integer i__;
integer j;
integer k1;
integer k2;
integer k3;
integer k4;
doublereal mul;

void init_vars() {
    // Set multiplier for scaling complex values
    mul = 2.5;

    // Define matrix dimensions to achieve ~100MB of data (assuming doublecomplex is 16 bytes)
    // We aim for roughly 6.25 million elements -> use square matrix of size ~2500x2500
    a_dim1 = 2500;
    integer n = 2500;

    // Allocate array large enough for n x n matrix
    a = (doublecomplex*)calloc(n * a_dim1, sizeof(doublecomplex));
    if (!a) {
        exit(1);
    }

    // Initialize some sample data
    for (int idx = 0; idx < n * a_dim1; ++idx) {
        a[idx].r = (doublereal)(idx % 123);
        a[idx].i = (doublereal)(idx % 456);
    }

    // Set loop bounds to ensure valid access within [1, n] indices (1-based indexing)
    i__1 = n;      // j from 1 to i__1
    k1 = n + 1;    // ensures i__3 = k1 - j >= 1 when j <= n
    k2 = 1;        // lower bound for i__
    k3 = n;        // upper bound candidate
    k4 = n + 10;   // another upper bound candidate
}