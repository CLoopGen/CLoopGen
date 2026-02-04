#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *i0;
extern doublereal *z__;
extern doublereal *tau;
extern doublereal *dmin__;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__;
extern integer j4;
extern doublereal emin;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Increased Stride (access every other original element)
    integer stride_j4;
    for (stride_j4 = *i0 << 2; stride_j4 <= i__1; stride_j4 += 8) {  // Double the increment: process every other original iteration
        j4 = stride_j4;  // Map logical j4
        z__[j4 - 3] = d__ + z__[j4];
        temp = z__[j4 + 2] / z__[j4 - 3];
        d__ = d__ * temp - *tau;
        *dmin__ = ((*dmin__) <= (d__) ? (*dmin__) : (d__));
        z__[j4 - 1] = z__[j4] * temp;
        d__1 = z__[j4 - 1];
        emin = ((d__1) <= (emin) ? (d__1) : (emin));
    }
    // Note: This variant skips half the iterations (strided execution), useful in hierarchical or decimation scenarios.
    // The effective work is reduced, but access pattern is now strided by 8 instead of 4.
}
