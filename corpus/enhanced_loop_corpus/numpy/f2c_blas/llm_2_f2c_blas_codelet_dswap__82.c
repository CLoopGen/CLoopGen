#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *dx;
extern doublereal *dy;
extern integer i__1;
extern integer i__;
extern integer mp1;
extern doublereal dtemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and accessing in increasing order of base pointer
    integer stride = 3;
    for (i__ = mp1; i__ <= i__1 - 2; i__ += stride) {
        doublereal temp0 = dx[i__];
        doublereal temp1 = dx[i__ + 1];
        doublereal temp2 = dx[i__ + 2];

        dx[i__] = dy[i__];
        dx[i__ + 1] = dy[i__ + 1];
        dx[i__ + 2] = dy[i__ + 2];

        dy[i__] = temp0;
        dy[i__ + 1] = temp1;
        dy[i__ + 2] = temp2;
    }
}
