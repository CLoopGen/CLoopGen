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
    // Variant 2: Strided memory access with a fixed stride of 4, skipping every few elements
    const integer stride = 4;
    for (i__ = mp1; i__ <= i__1; i__ += stride) {
        if (i__ <= i__1) {
            dtemp = dx[i__];
            dx[i__] = dy[i__];
            dy[i__] = dtemp;
        }
        integer j1 = i__ + 1;
        if (j1 <= i__1) {
            dtemp = dx[j1];
            dx[j1] = dy[j1];
            dy[j1] = dtemp;
        }
        integer j2 = i__ + 2;
        if (j2 <= i__1) {
            dtemp = dx[j2];
            dx[j2] = dy[j2];
            dy[j2] = dtemp;
        }
    }
}
