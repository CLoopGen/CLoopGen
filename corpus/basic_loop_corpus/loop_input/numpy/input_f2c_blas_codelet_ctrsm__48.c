#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
singlecomplex *b;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    // Set dimensions to achieve ~0.01 seconds runtime
    // Assume typical CPU can do ~1e9 iterations/sec, so aim for ~1e7 operations
    // Outer loop: i__1 ≈ 4000, inner loop: *m ≈ 4000 => total ~16e6 iterations
    i__1 = 4000;
    b_dim1 = 5000;  // Ensure stride is large enough to avoid overlap
    m = (integer*)malloc(sizeof(integer));
    *m = 4000;

    // Allocate b with size (b_dim1 + 1) * max(i__) to prevent out-of-bounds access
    // Max index: i__ + j * b_dim1 <= 4000 + 4000 * 5000 = 4000 + 20,000,000 = 20,004,000
    b = (singlecomplex*)calloc(b_dim1 * i__1 + *m + 1, sizeof(singlecomplex));
}