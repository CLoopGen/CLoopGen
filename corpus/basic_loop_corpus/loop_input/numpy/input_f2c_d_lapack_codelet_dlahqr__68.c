#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *ilo = NULL;
doublereal *h__ = NULL;
integer h_dim1;
integer i__1;
integer j;

void init_vars() {
    // Allocate and initialize ilo
    ilo = (integer*)malloc(sizeof(integer));
    *ilo = 2;

    // Set matrix dimension and loop upper bound to ensure memory safety
    h_dim1 = 1000;
    i__1 = 998;  // ensures j+3 <= h_dim1 when j <= i__1

    // Allocate h__ as a large 2D array (row-major layout), size ~8MB to hit ~0.01s runtime
    int rows = h_dim1 + 5;
    int cols = h_dim1 + 5;
    h__ = (doublereal*)calloc(rows * cols, sizeof(doublereal));
}