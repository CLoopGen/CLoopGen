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
    // Set dimensions to achieve roughly 0.01 seconds runtime
    // Assuming typical modern CPU can do ~1e9 iterations/sec, aim for ~1e7 operations
    // We'll set m = 4096 and i__1 = 4096, giving ~16.7M iterations which is in range

    b_dim1 = 8192;  // leading dimension of array b (must be >= m)
    *m = 8192;
    i__1 = 8192;

    // Allocate b as a 2D array with dimensions [b_dim1+1][b_dim1+1] (1-indexed)
    // Total size: ~8192*8192*sizeof(singlecomplex) ≈ 512MB
    // Reduce slightly to stay within suggested bounds (~256MB max)
    // Let's use 4096 x 4096 → ~128MB
    b_dim1 = 4096;
    *m = 4096;
    i__1 = 4096;

    // Now allocate memory
    m = (integer*)malloc(sizeof(integer));
    *m = 4096;

    // Allocate b with padding for 1-based indexing: (b_dim1+1) * (b_dim1+1)
    b = (singlecomplex*)calloc((b_dim1 + 1) * (b_dim1 + 1), sizeof(singlecomplex));
}

// Define all external variables at file scope
integer _m_storage = 0;
integer *m = &_m_storage;
singlecomplex *b = NULL;
integer b_dim1 = 0;
integer i__1 = 0;
integer i__2 = 0;
integer i__3 = 0;
integer i__ = 0;
integer j = 0;