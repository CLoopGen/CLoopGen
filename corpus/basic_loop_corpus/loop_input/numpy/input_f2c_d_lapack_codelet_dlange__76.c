#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *m;
doublereal *a;
doublereal *work;
integer a_dim1;
integer i__1;
integer i__2;
doublereal d__1;
integer i__;
integer j;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Assume matrix size around 1000x1000 gives reasonable time
    i__1 = 1000;        // outer loop bound (number of columns)
    *m = 1000;          // inner loop bound (number of rows)
    a_dim1 = 1000;      // leading dimension of matrix 'a'

    // Allocate arrays with sufficient size: a[m x i__1], work[m]
    a = (doublereal*)calloc(a_dim1 * i__1, sizeof(doublereal));
    work = (doublereal*)calloc(*m, sizeof(doublereal));

    // Initialize d__1 to 0 (used as temporary, but must be safe)
    d__1 = 0.0;

    // Ensure all pointers are valid and data initialized
}

// Define m as a pointer to integer, allocate and initialize it
static integer m_storage = 1000;
integer *m = &m_storage;

// Other global variables
doublereal *a = NULL;
doublereal *work = NULL;
integer a_dim1 = 1000;
integer i__1 = 1000;
integer i__2;
doublereal d__1 = 0.0;
integer i__ = 0;
integer j = 0;