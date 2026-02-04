#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double doublereal;
typedef int integer;

doublereal *a = NULL;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
integer i__;
integer j;
integer k1;
integer k2;
integer k3;
integer k4;
doublereal mul;

void init_vars() {
    // Set matrix dimensions and parameters to ensure meaningful computation
    a_dim1 = 8000;  // leading dimension
    i__1 = 6000;    // j-loop bound
    k1 = 7000;
    k2 = 1000;
    k3 = 7500;
    k4 = 8000;
    mul = 1.5;

    // Allocate approximately 64MB of data (8000x8000 doubles ~ 512MB, but we'll use subregion)
    // We only need enough so that the loop runs ~0.01s, so smaller allocation is fine
    // Adjusted to ~16-32MB for expected performance on modern CPU
    size_t total_size = (size_t)a_dim1 * a_dim1 * sizeof(doublereal);
    
    // Allocate and initialize array
    a = (doublereal*)calloc(a_dim1, a_dim1 * sizeof(doublereal));
    if (!a) {
        exit(1);
    }

    // Ensure loop bounds are safe: j from 1 to i__1, i from max(k1-j,k2) to min(k3,k4-j)
    // Need to make sure indices stay within [0, a_dim1-1] for both i and j
    // With current settings: j <= 6000, i >= 1000, i <= 7500, so i+j*a_dim1 <= 7500+6000*8000 = ~48e6 index -> safe since total ~64M elements
}