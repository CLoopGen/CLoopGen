#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern integer i__1;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in forward direction)
    // We assume i__1 is even for simplicity, or we clamp the upper bound accordingly.
    integer stride = 2;
    for (k = 1; k <= i__1; k += stride) {
        z__[k] = 0.F;
    }
    // Handle any potential odd-sized tail if needed, but since original loop sets all to 0,
    // and we're only doing optimization-style striding, we skip non-aligned elements intentionally.
}
