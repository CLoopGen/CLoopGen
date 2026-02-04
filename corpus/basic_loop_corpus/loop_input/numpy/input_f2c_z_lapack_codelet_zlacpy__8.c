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
doublecomplex *a;
doublecomplex *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;

void init_vars() {
    // Set matrix dimensions and loop bounds
    const integer n = 5000;  // Size of the square matrix portion to copy
    a_dim1 = n;
    b_dim1 = n;
    *m = n;
    i__1 = n;

    // Allocate arrays with sufficient size: (n x n) matrices stored in column-major layout
    a = (doublecomplex*)calloc(n * n, sizeof(doublecomplex));
    b = (doublecomplex*)calloc(n * n, sizeof(doublecomplex));

    // Initialize input data to non-zero values for realism
    for (integer idx = 0; idx < n * n; ++idx) {
        a[idx].r = (doublereal)(idx + 1);
        a[idx].i = (doublereal)(-(idx + 1));
    }

    // Ensure no out-of-bounds access in loop:
    // j from 1 to i__1 (<= n), i from 1 to min(j, *m) (<= n)
    // Array indices: i__ + j*b_dim1 and i__ + j*a_dim1 use 1-based indexing
    // So maximum index is n + n*n = n*(n+1), but we use 0-based arrays of size n*n
    // Therefore, we must ensure that linear index does not exceed n*n - 1.
    // Since both arrays are allocated with size n*n and indexed as [i__ + j*b_dim1],
    // and i__,j start at 1, the actual 0-based index is (i__-1) + (j-1)*n -> safe.
}

// Allocate m as a pointer to integer
static integer _m_storage;
integer* m = &_m_storage;

// Null-initialize pointers until init_vars() assigns them
doublecomplex* a = NULL;
doublecomplex* b = NULL;