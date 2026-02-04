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
    // Variant 1: Consecutive memory access with unrolling restructured for sequential stride
    // Instead of accessing dx[i__], dx[i__+1], etc., we use a local index and consecutive loads
    integer idx = mp1;
    for (i__ = mp1; i__ <= i__1 - 4; i__ += 5) {
        dtemp += dx[idx] * dy[idx];
        dtemp += dx[idx + 1] * dy[idx + 1];
        dtemp += dx[idx + 2] * dy[idx + 2];
        dtemp += dx[idx + 3] * dy[idx + 3];
        dtemp += dx[idx + 4] * dy[idx + 4];
        idx += 5;
    }
}
