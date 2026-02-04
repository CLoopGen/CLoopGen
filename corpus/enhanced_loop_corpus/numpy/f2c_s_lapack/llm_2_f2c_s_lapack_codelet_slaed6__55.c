#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern real *z__;
extern integer i__;
extern real dscale[3];
extern real zscale[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (wrapping around using modulo)
    // This changes the access pattern to non-consecutive, simulating strided access.
    for (i__ = 0; i__ < 3; ++i__) {
        int index = (2 * i__ + 1) % 4;  // Generates sequence: 1, 3, 2 (valid indices: 1..3)
        dscale[i__] = d__[index];
        zscale[i__] = z__[index];
    }
}
