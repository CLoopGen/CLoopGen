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
    // Set matrix dimensions to achieve ~100ms runtime
    // The loop runs over a lower triangular portion up to min(j, *m)
    // To get significant work, set size such that total iterations ~10s of millions
    const int size = 4096;  // This gives about (size^2)/2 operations ~8M
    const int alloc_size = size * size * sizeof(doublereal);

    // Allocate matrices a and b
    a = (doublereal*)aligned_alloc(32, alloc_size);
    b = (doublereal*)aligned_alloc(32, alloc_size);

    if (!a || !b) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize matrix dimensions
    a_dim1 = size;
    b_dim1 = size;
    m = (integer*)malloc(sizeof(integer));
    *m = size;
    i__1 = size;  // outer loop bound

    // Initialize input data
    for (int idx = 0; idx < size * size; ++idx) {
        a[idx] = (doublereal)(idx % 1000) / 100.0;
        b[idx] = 0.0;
    }
}