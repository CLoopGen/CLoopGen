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
singlecomplex *alpha;
singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Assume a typical modern CPU can handle this with matrix size around 4000x4000 => ~64 MB of data

    const int n = 4096;  // Square matrix dimension
    const int total_elements = n * n;

    // Allocate and initialize alpha
    alpha = (singlecomplex*)calloc(1, sizeof(singlecomplex));
    alpha->r = 1.0f;
    alpha->i = 0.5f;

    // Allocate large enough array 'a' to prevent out-of-bounds access
    a = (singlecomplex*)calloc(total_elements, sizeof(singlecomplex));

    // Set m to control outer loop bound via i__2 = *m
    m = (integer*)malloc(sizeof(integer));
    *m = n;  // So i__2 = *m = n

    // Set a_dim1 to be the leading dimension of matrix a (column-major assumed)
    a_dim1 = n;

    // Set i__1: upper bound for j in outer loop
    i__1 = n - 1;  // Ensures j <= n-1, so i__ starts at j+1 <= n

    // Initialize other loop indices to safe values (will be overwritten in loop)
    i__2 = 0;
    i__3 = 0;
    i__ = 0;
    j = 0;
}