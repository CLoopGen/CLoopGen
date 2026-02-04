#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *n;
doublereal *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // The loop runs approximately (i__1 * (*n - j + 1)) iterations on average
    // We aim for several million iterations to get measurable time without being too large
    *n = 4096;
    i__1 = 4096;
    c_dim1 = *n;
    
    // Allocate and initialize c__ matrix as 2D array in column-major layout
    c__ = (doublereal*)calloc((*n + 1) * (i__1 + 1), sizeof(doublereal));
    
    // Ensure indices start within valid range
    i__ = 1;
    j = 1;
    i__2 = *n;
}

// Define global variables after declaration
integer n_storage = 0;
doublereal* c__ = NULL;
integer c_dim1 = 0;
integer i__1 = 0;
integer i__2 = 0;
integer i__ = 0;
integer j = 0;

// Redirect pointer to n to point to n_storage
integer* n = &n_storage;