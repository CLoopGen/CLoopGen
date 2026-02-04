#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *n;
real *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // The loop iterates over approximately (i__1) * (average of (n - j + 1)) elements
    // To get around 10-100 million operations, set n and i__1 appropriately

    const int N = 4096;  // Size for reasonable memory usage and timing

    // Allocate array c__ with dimensions [N+1][N+1] using column-major layout
    // We use 1-based indexing as implied by the loop starting at 1
    c__ = (real*)calloc((N+1) * (N+1), sizeof(real));
    if (!c__) exit(1);

    n = (integer*)malloc(sizeof(integer));
    if (!n) exit(1);
    *n = N;

    c_dim1 = N+1;  // leading dimension
    i__1 = N;      // outer loop bound
}