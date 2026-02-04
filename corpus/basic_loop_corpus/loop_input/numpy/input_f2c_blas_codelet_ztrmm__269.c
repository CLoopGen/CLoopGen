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
doublecomplex *b;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Assume modern CPU can handle ~1e8 operations per second; target ~1e6 iterations
    i__1 = 1000;          // outer loop bound
    b_dim1 = 1001;        // leading dimension for b (j * b_dim1 indexing)
    m = (integer*)malloc(sizeof(integer));
    *m = 1000;            // inner loop bound

    // Allocate b with safe size: max index is i__ + j * b_dim1 <= 1000 + 1000*1001 = 1001000
    b = (doublecomplex*)calloc(b_dim1 * (i__1 + 1), sizeof(doublecomplex)); // +1 to avoid off-by-one
}

// Ensure variables are defined at file scope and accessible by loop()