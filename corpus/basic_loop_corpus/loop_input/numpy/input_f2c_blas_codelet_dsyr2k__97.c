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
    const size_t target_size = 128 * 1024 * 1024; // Aim for ~128MB
    const size_t element_size = sizeof(doublereal);
    const size_t total_elements = target_size / element_size;
    
    // Choose n such that n*(n+1)/2 is reasonable, but we allocate n*n
    // We'll set n to about sqrt(total_elements)
    *n = (integer)10000; // ~10000x10000 matrix gives 100M elements, ~800MB -> too big
    // Adjust down to get ~16M elements for ~128MB
    *n = (integer)4096; // 4096*4096 = ~16.7M elements, ~134MB

    c_dim1 = *n;
    i__1 = *n; // outer loop j from 1 to n
    // Allocate c__ as a 2D array of size [n+1][n+1], 1-indexed
    c__ = (doublereal*)calloc((*n + 1) * (*n + 1), sizeof(doublereal));
    if (!c__) {
        exit(1);
    }
}
// Initialize pointers and scalars
integer n_storage = 0;
doublereal c_storage[1] = {0.0};

integer i__1_storage = 0;
integer i__2_storage = 0;
integer i__storage = 0;
integer j_storage = 0;

// Define external symbols
integer *n = &n_storage;
doublereal *c__ = c_storage;
integer c_dim1 = 1;
integer i__1 = 0;
integer i__2 = 0;
integer i__ = 0;
integer j = 0;

// Redefine after declaration to ensure correct initialization order
void init_vars();

__attribute__((constructor))
static void initialize() {
    init_vars();
}