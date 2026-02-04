#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern real *delta;
extern integer i__1;
extern integer j;
extern real psi;
extern real dpsi;
extern real temp;
extern real erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive elements, access every second element in a strided manner.
    // We assume i__1 is even for simplicity, or we adjust the loop bound accordingly.
    integer stride = 2;
    integer upper_bound = (i__1 % 2 == 0) ? i__1 : i__1 - 1; // Ensure we don't go out of bounds
    for (j = 1; j <= upper_bound; j += stride) {
        temp = z__[j] / delta[j];
        psi += z__[j] * temp;
        dpsi += temp * temp;
        erretm += psi;
    }
}
