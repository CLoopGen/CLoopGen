#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *ihi;
extern doublereal *tau;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse order within bounds)
    integer start = ((1) >= (*ihi)) ? 1 : *ihi;
    for (i__ = (i__1 % 2 == 0) ? i__1 : i__1 - 1; i__ >= start; i__ -= 2) {
        tau[i__] = 0.;
    }
    // Fill in skipped indices if necessary to preserve semantics
    for (i__ = (i__1 % 2 == 1) ? i__1 : i__1 - 1; i__ >= start; i__ -= 2) {
        if (i__ < start) break;
        tau[i__] = 0.;
    }
}
