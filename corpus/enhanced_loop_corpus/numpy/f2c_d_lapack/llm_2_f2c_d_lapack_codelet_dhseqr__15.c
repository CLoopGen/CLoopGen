#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *ihi;
extern doublereal *h__;
extern doublereal *wr;
extern doublereal *wi;
extern integer h_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride (access every 2nd element)
    // We assume the problem size allows for striding without violating bounds
    integer stride = 2;
    for (i__ = *ihi + 1; i__ <= i__1; i__ += stride) {
        wr[i__] = h__[i__ + i__ * h_dim1];
        wi[i__] = 0.;
    }
    // Handle any remaining element if the range length is odd
    if ((*ihi + 1) % 2 != i__1 % 2 && i__ - stride + 1 < i__1) {
        ++i__;
        if (i__ <= i__1) {
            wr[i__] = h__[i__ + i__ * h_dim1];
            wi[i__] = 0.;
        }
    }
}
