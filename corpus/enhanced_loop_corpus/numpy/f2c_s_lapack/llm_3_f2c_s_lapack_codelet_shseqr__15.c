#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *ihi;
extern real *h__;
extern real *wr;
extern real *wi;
extern integer h_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access with offset-based indexing (forward traversal with pointer arithmetic simulation)
    integer base_idx = *ihi + 1;
    for (i__ = 0; i__ <= i__1 - base_idx; ++i__) {
        integer idx = base_idx + i__;
        wr[idx] = h__[idx + idx * h_dim1];
        wi[idx] = 0.F;
    }
}
