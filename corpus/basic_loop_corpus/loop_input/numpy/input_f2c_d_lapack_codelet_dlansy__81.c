#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *n;
doublereal *a;
integer a_dim1;
integer i__1;
integer i__2;
doublereal d__1;
doublereal d__2;
doublereal d__3;
integer i__;
integer j;
doublereal value;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Empirical tuning: for a 2D-like loop with triangular access, aim for total iterations ~1e7
    // Let n_size be such that sum_{j=1}^{n} (n - j + 1) ≈ n^2 / 2 ≈ 1e7 → n ≈ 4500
    const int n_size = 4500;

    // Allocate and initialize n
    n = (integer*)malloc(sizeof(integer));
    *n = n_size;

    // Allocate 2D array a[n_size][n_size], stored column-major (Fortran-style)
    a_dim1 = n_size; // leading dimension
    a = (doublereal*)calloc(n_size * n_size, sizeof(doublereal));

    // Initialize i__1 to *n to control outer loop: j from 1 to *n
    i__1 = *n;

    // Initialize value to a small number so max comparisons update it
    value = 0.0;

    // Ensure inner loop bounds are safe: i__ starts at j, ends at i__2 = *n
    i__2 = *n;

    // Initialize other temps to zero (they are used in macro-like expressions)
    d__1 = d__2 = d__3 = 0.0;
    i__ = j = 0;
}