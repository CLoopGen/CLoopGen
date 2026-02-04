#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef float real;
typedef int integer;

typedef struct {
    real r;
    real i;
} singlecomplex;

real *beta;
singlecomplex *c__;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
real r__1;
singlecomplex q__1;
integer i__;
integer j;

void init_vars() {
    // Allocate beta on heap and assign pointer
    static real beta_val = 1.5f;
    beta = &beta_val;

    // Set matrix dimension size to ensure sufficient workload (~0.01 sec)
    // The loop runs approximately O(n^2) iterations, aiming for ~10-20 million total writes
    i__1 = 2048;  // outer loop: j from 1 to 2048
    c_dim1 = i__1; // leading dimension

    // Total size: c_dim1 * i__1 = 2048*2048 = ~4M elements, ~32 MB (each complex is 8 bytes)
    size_t c_size = (size_t)c_dim1 * (size_t)i__1;
    c__ = (singlecomplex*)calloc(c_size, sizeof(singlecomplex));
    if (!c__) {
        exit(1);
    }

    // Initialize c__ with non-zero values to make scaling visible
    for (size_t idx = 0; idx < c_size; ++idx) {
        c__[idx].r = (real)(idx % 128) * 0.1f;
        c__[idx].i = (real)(idx % 64) * 0.05f;
    }

    // Ensure all used indices in the loop stay within [0, c_dim1*i__1 - 1]
    // Loop uses: i + j*c_dim1, where i <= j-1 and j <= i__1
    // Max index: (j-1) + j*c_dim1 <= (i__1-1) + i__1*c_dim1 = (i__1-1) + i__1*i__1
    // Since c_dim1 = i__1, max index is (i__1 - 1) + i__1*i__1 = i__1*(i__1+1) - 1
    // Our allocated size is i__1 * i__1, but we access up to i__1*(i__1+1)-1 => need at least i__1*(i__1+1)
    // So we must adjust allocation to prevent out-of-bounds access

    free(c__);
    size_t required_size = (size_t)i__1 * ((size_t)i__1 + 1);
    c__ = (singlecomplex*)calloc(required_size, sizeof(singlecomplex));
    if (!c__) {
        exit(1);
    }

    // Re-initialize safely
    for (size_t idx = 0; idx < required_size; ++idx) {
        c__[idx].r = (real)((idx % 256) + 1) * 0.1f;
        c__[idx].i = (real)(idx % 128) * 0.05f;
    }
}