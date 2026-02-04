#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern integer *indxq;
extern doublereal *z__;
extern doublereal *dlamda;
extern doublereal *w;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process elements in a non-unit stride pattern
    // Use a stride of 2 for better cache behavior analysis or vectorization testing
    // Handle odd i__1 with proper bounds check via conditional evaluation
    integer stride = 2;
    integer limit = i__1;

    // Unroll the indirect index lookup with strided traversal
    for (i__ = 1; i__ <= limit; i__ += stride) {
        integer j1 = i__;
        integer j2 = i__ + 1;
        integer idx1 = indxq[j1];
        dlamda[j1] = d__[idx1];
        w[j1] = z__[idx1];

        if (j2 <= limit) {
            integer idx2 = indxq[j2];
            dlamda[j2] = d__[idx2];
            w[j2] = z__[idx2];
        }
    }
}
