#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *m;
doublereal *alpha;
doublereal *a;
doublereal *x;
integer *incx;
doublereal *y;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer jx;
doublereal temp;

void init_vars() {
    // Problem dimensions
    const integer M = 2000;  // Number of rows in matrix 'a' and length of vector 'y'
    const integer N = 1500;  // Number of columns in matrix 'a' and effective length of vector 'x'

    // Allocate memory for scalar variables
    m = (integer*)malloc(sizeof(integer));
    alpha = (doublereal*)malloc(sizeof(doublereal));
    incx = (integer*)malloc(sizeof(integer));

    // Set values
    *m = M;
    *alpha = 1.5;
    *incx = 1;

    // Compute leading dimension and column count for loop
    a_dim1 = M;  // leading dimension of matrix 'a', column-major storage
    i__1 = N;    // upper bound for j-loop

    // Allocate arrays
    a = (doublereal*)calloc(M * N, sizeof(doublereal));
    x = (doublereal*)calloc(N, sizeof(doublereal));
    y = (doublereal*)calloc(M, sizeof(doublereal));

    // Initialize with non-zero meaningful data to trigger conditional logic
    for (integer idx = 0; idx < N; ++idx) {
        x[idx] = (doublereal)(idx + 1);
    }
    for (integer idx = 0; idx < M * N; ++idx) {
        a[idx] = 1.0;  // simple initialization
    }

    // Initialize temp and loop indices
    temp = 0.0;
    i__ = 1;
    j = 1;
    jx = 1;  // Fortran-style 1-based indexing used in original loop

    // Ensure that the loop bounds and pointer arithmetic stay within allocated ranges
}