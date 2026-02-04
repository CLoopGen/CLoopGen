#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *h__;
extern doublereal *wr;
extern doublereal *wi;
extern integer h_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every second element)
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        wr[i__] = h__[i__ + i__ * h_dim1];
        wi[i__] = 0.;
    }
    // Handle odd-sized ranges by processing remaining element if i__1 is even and loop ended early
    if (i__1 % 2 == 0 && i__1 >= 1) {
        wr[i__1] = h__[i__1 + i__1 * h_dim1];
        wi[i__1] = 0.;
    }
}
