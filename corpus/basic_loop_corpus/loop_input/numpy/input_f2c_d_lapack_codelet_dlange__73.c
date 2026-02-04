#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *m;
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
    // Set dimensions
    const integer rows = 5000;
    const integer cols = 5000;

    // Allocate memory for a: 2D array of size rows x cols
    a = (doublereal*)calloc(rows * cols, sizeof(doublereal));
    if (!a) {
        exit(1);
    }

    // Initialize matrix with non-zero values to ensure meaningful computation
    for (integer idx = 0; idx < rows * cols; ++idx) {
        a[idx] = sin(idx % 100) * 1.5;
    }

    // Set external variables
    m = (integer*)malloc(sizeof(integer));
    if (!m) {
        exit(1);
    }
    *m = rows;         // number of rows

    a_dim1 = rows;     // leading dimension (row stride)
    i__1 = cols;       // loop over columns j = 1 to i__1
    value = 0.0;       // initial value

    // Ensure loop bounds are valid: j from 1 to i__1, i__ from 1 to *m
    // Fortran-style indexing assumed: a[i__ + j * a_dim1] => index = (i__-1) + (j-1)*a_dim1
    // So maximum index is (*m - 1) + (i__1 - 1) * a_dim1 = (rows-1) + (cols-1)*rows = rows*cols - 1
    // Which is within allocated bounds [0, rows*cols)
}

// DO NOT include main, headers, explanations or comments below