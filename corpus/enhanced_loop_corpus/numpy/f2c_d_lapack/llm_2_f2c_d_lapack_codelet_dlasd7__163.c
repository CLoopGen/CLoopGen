#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern doublereal *vf;
extern doublereal *beta;
extern integer i__1;
extern integer i__;
extern integer nlp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i__ = nlp2; i__ <= i__1; i__ += 2) {
        z__[i__] = *beta * vf[i__];
        vf[i__] = 0.;
    }
    // Handle remaining element if the range is odd
    if ((i__1 - nlp2 + 1) % 2 != 0 && i__1 >= nlp2) {
        i__ = i__1;
        z__[i__] = *beta * vf[i__];
        vf[i__] = 0.;
    }
}
