#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *x;
extern integer i__1;
extern integer i__2;
extern doublereal d__1;
extern integer ix;
extern doublereal ssq;
extern doublereal scale;
extern doublereal absxi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ix = 1; i__2 < 0 ? ix >= i__1 : ix <= i__1; ix += i__2) {
    absxi = (d__1 = x[ix], ((d__1) >= 0 ? (d__1) : -(d__1)));
    if (scale < absxi) {
        d__1 = scale / absxi;
        ssq = ssq * (d__1 * d__1) + 1.;
        scale = absxi;
    } else {
        d__1 = absxi / scale;
        ssq += d__1 * d__1;
    }
}
}
