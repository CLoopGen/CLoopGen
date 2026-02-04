#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *m;
doublereal *a;
doublereal *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    // Problem size: aim for ~100MB of data to target ~0.01s runtime
    const integer rows = 8000;   // m = number of rows
    const integer cols = 4000;   // number of columns

    // Allocate memory for arrays a and b (size rows * cols)
    a = (doublereal *)calloc(rows * cols, sizeof(doublereal));
    b = (doublereal *)calloc(rows * cols, sizeof(doublereal));

    // Initialize dimensions and loop bounds
    m = &rows;
    a_dim1 = rows;
    b_dim1 = rows;
    i__1 = cols;  // outer loop j from 1 to cols
    i__2 = rows;  // inner loop i from 1 to rows

    // Initialize input array a with non-zero values to make copy observable
    for (integer idx = 0; idx < rows * cols; ++idx) {
        a[idx] = (doublereal)(idx + 1);
    }

    // Ensure Fortran-style indexing: elements accessed as [i + j * dim]
    // Our arrays are column-major compatible with assumed Fortran layout
}