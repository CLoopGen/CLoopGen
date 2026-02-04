#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use consecutive memory access by reordering computation and introducing base pointer offsets
    // We precompute base indices to flatten access and promote sequential memory layout usage
    // This improves cache locality by accessing nearby elements in inner loop
    integer base_j, base_j_prev;
    for (j = *m; j >= 2; --j) {
        base_j = j * a_dim1;
        a[base_j + 1] = 0.F;
        i__1 = *m;
        base_j_prev = (j - 1) * a_dim1;  // Precomputed previous column base
        for (i__ = j + 1; i__ <= i__1; ++i__) {
            // Consecutive-like access by flattening index arithmetic
            a[i__ + base_j] = a[i__ + base_j_prev];
        }
    }
}
