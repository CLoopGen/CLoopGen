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
singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer kk;

static singlecomplex *a_storage = NULL;
static integer m_storage;

void init_vars() {
    // Set problem size to target ~0.01 seconds runtime
    // Heuristic: use matrix of size ~5000x5000 complex elements (each 8 bytes) -> ~200MB
    const integer n = 5000;

    // Allocate and initialize the 2D array 'a' as a linear block of size (n+1) * (n+1) to allow 1-based indexing
    a_storage = (singlecomplex*)calloc((n + 1) * (n + 1), sizeof(singlecomplex));
    if (!a_storage) {
        exit(1);
    }
    a = a_storage;

    // Set dimensions and loop bounds
    m_storage = n;
    m = &m_storage;

    a_dim1 = n;      // leading dimension
    kk = n / 2;      // start row index (half of n)
    i__1 = n;        // upper bound for j loop

    // Ensure all accesses in loop are within [1..n] x [1..n]
}
// Do NOT include main(), headers, explanations or comments.