#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *da;
extern doublereal *dx;
extern doublereal *dy;
extern integer i__1;
extern integer i__;
extern integer mp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic
    doublereal *dyp = &dy[mp1];
    doublereal *dxp = &dx[mp1];
    integer count = (i__1 - mp1 + 1) / 4;
    for (integer j = 0; j < count; ++j) {
        dyp[0] += *da * dxp[0];
        dyp[1] += *da * dxp[1];
        dyp[2] += *da * dxp[2];
        dyp[3] += *da * dxp[3];
        dyp += 4;
        dxp += 4;
    }
}
