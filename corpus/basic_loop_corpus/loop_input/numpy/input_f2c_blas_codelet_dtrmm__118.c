#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer *m;
doublereal *alpha;
doublereal *a;
doublereal *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer k;
doublereal temp;
logical nounit;

void init_vars() {
    // Allocate and initialize scalar variables
    m = (integer*)malloc(sizeof(integer));
    alpha = (doublereal*)malloc(sizeof(doublereal));
    *m = 1000;          // Size of matrix dimension
    *alpha = 1.5;
    a_dim1 = *m;        // Leading dimension of square matrix 'a'
    b_dim1 = *m;        // Leading dimension of matrix 'b'

    // Set loop bound i__1 to be the number of columns processed (full matrix)
    i__1 = *m;

    // Initialize nounit flag (true means diagonal is not assumed to be unity)
    nounit = 1;

    // Allocate matrices a and b as column-major 2D arrays of size m x m
    a = (doublereal*)calloc((*m) * (*m), sizeof(doublereal));
    b = (doublereal*)calloc((*m) * (*m), sizeof(doublereal));

    // Initialize matrix a: fill with non-zero values below diagonal, random on and above
    for (k = 1; k <= i__1; ++k) {
        for (j = 1; j <= k; ++j) {
            a[j - 1 + (k - 1) * a_dim1] = (j < k) ? ((double)rand() / RAND_MAX) : 1.0;
        }
    }

    // Initialize matrix b with random data
    for (i__ = 1; i__ <= *m; ++i__) {
        for (j = 1; j <= *m; ++j) {
            b[i__ - 1 + (j - 1) * b_dim1] = (double)rand() / RAND_MAX;
        }
    }

    // Ensure temp is initialized to avoid undefined behavior
    temp = 0.0;
}