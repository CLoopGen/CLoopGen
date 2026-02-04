#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *tau;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in forward pass, then odd indices)
    for (i__ = 2; i__ <= i__1; i__ += 2) {
        tau[i__] = 0.;
    }
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        tau[i__] = 0.;
    }
}
