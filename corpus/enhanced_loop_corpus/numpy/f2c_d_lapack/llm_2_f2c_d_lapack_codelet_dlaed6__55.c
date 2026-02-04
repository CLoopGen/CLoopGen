#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *z__;
extern integer i__;
extern doublereal dscale[3];
extern doublereal zscale[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (wrapping around using modulo)
    // This changes the access pattern to non-consecutive, strided indexing
    for (i__ = 0; i__ < 3; ++i__) {
        int index = (2 * i__) % 3;  // Stride of 2 with wrap-around
        dscale[index] = d__[index + 1];
        zscale[index] = z__[index + 1];
    }
}
