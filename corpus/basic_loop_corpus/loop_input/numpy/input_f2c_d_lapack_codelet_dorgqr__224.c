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
integer i__;
integer j;
integer kk;

void init_vars() {
    // Set matrix dimensions to achieve desired memory size (~64MB for data)
    // We aim for sufficient operations to take ~0.01 seconds
    a_dim1 = 8000;  // leading dimension
    kk = 8000;      // outer loop bound
    i__1 = 8000;    // upper bound for j

    // Allocate 2D array as column-major: [a_dim1][i__1] elements
    a = (doublereal*)calloc((size_t)a_dim1 * (size_t)i__1, sizeof(doublereal));
    if (!a) {
        exit(1);
    }

    // Ensure loops run safely:
    // j from kk+1 to i__1 -> only runs if kk+1 <= i__1
    // Here kk == i__1, so j starts at 8001 and i__1 is 8000 -> inner loop does not execute
    // But we want the loop to run meaningfully, so adjust bounds.

    // Adjust so that kk < i__1 to allow j-loop to run
    kk = 7999;
    i__1 = 8000;

    // Now j will be 8000 only, and i__ goes from 1 to kk (7999)
    // Then a[i__ + j*a_dim1] = a[i__ + 8000*8000] = a[i__ + 64000000], i__ from 1 to 7999
    // So max index = 64000000 + 7999 = 64007999, which must be < total size (64M)
    // Total allocated: 8000 * 8000 = 64,000,000 -> indices 0..63999999
    // But index 64000000 + 1 = 64000001 exceeds!

    // Fix: reduce dimensions so access stays in bounds
    a_dim1 = 8000;
    kk = 7999;
    i__1 = 8000;

    // Free old allocation and reallocate with safe size
    free(a);
    // Maximum row index: i__ <= kk => i__ <= 7999
    // Maximum col index: j <= i__1 => j <= 8000
    // Max access: i__ + j*a_dim1 <= 7999 + 8000*8000 = 7999 + 64,000,000 = 64,007,999
    // So we need at least 64,008,000 elements
    size_t total_size = (size_t)(a_dim1 + 1) * (size_t)(i__1 + 1); // Add padding
    a = (doublereal*)calloc(total_size, sizeof(doublereal));
    if (!a) {
        exit(1);
    }
}