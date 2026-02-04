#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *nl;
extern real *d__;
extern real *z__;
extern real *vf;
extern real *vl;
extern real *alpha;
extern integer *idxq;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (stride of 2, unrolled by factor 2)
    // Process elements in reverse with stride-2 access to simulate irregular memory pattern
    // Boundary adjusted to ensure safe access
    integer start = (*nl / 2) * 2; // Round down to even index
    for (i__ = start; i__ >= 2; i__ -= 2) {
        // Handle two indices at once with stride
        z__[i__ + 1] = *alpha * vl[i__];
        z__[i__    ] = *alpha * vl[i__ - 1];
        
        vl[i__] = 0.F;
        vl[i__ - 1] = 0.F;
        
        vf[i__ + 1] = vf[i__];
        vf[i__    ] = vf[i__ - 1];
        
        d__[i__ + 1] = d__[i__];
        d__[i__    ] = d__[i__ - 1];
        
        idxq[i__ + 1] = idxq[i__] + 1;
        idxq[i__    ] = idxq[i__ - 1] + 1;
    }
    // Handle leftover element if nl is odd
    if (*nl % 2 == 1 && i__ == 1) {
        z__[i__ + 1] = *alpha * vl[i__];
        vl[i__] = 0.F;
        vf[i__ + 1] = vf[i__];
        d__[i__ + 1] = d__[i__];
        idxq[i__ + 1] = idxq[i__] + 1;
    }
}
