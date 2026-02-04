#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer *n;
doublereal *a;
doublereal *x;
integer *incx;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer ix;
integer jx;
doublereal temp;
logical nounit;

void init_vars() {
    const integer data_size = 4096; // Approximate size for ~0.01s runtime
    const integer matrix_size = data_size;
    const integer vector_size = data_size;

    n = (integer*)malloc(sizeof(integer));
    *n = vector_size;

    incx = (integer*)malloc(sizeof(integer));
    *incx = 1;

    a_dim1 = matrix_size;

    i__1 = *n - 1; // Ensures j goes from 1 to n-1 so that inner loop stays in bounds
    nounit = 1;

    // Allocate and initialize x vector
    x = (doublereal*)calloc(vector_size + abs(*incx) * (*n - 1) + 10, sizeof(doublereal));
    for (integer idx = 0; idx < vector_size; ++idx) {
        x[idx] = sin(idx);
    }

    // Allocate and initialize 2D matrix a as column-major
    a = (doublereal*)calloc(matrix_size * matrix_size, sizeof(doublereal));
    for (integer col = 0; col < matrix_size; ++col) {
        for (integer row = 0; row < matrix_size; ++row) {
            a[row + col * a_dim1] = (doublereal)(fabs(col - row) < 5 ? 1.0 / (1.0 + fabs(col - row)) : 0.0);
        }
    }

    // Initialize index variables
    jx = 0; // Start at beginning of x array
}