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
    // Variant 2: Reverse consecutive memory access (processing from high to low index)
    for (i__ = i__1; i__ >= nlp2; --i__) {
        z__[i__] = *beta * vf[i__];
        vf[i__] = 0.;
    }
}
