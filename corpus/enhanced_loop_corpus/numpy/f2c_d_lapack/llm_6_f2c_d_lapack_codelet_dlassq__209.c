#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *x;
extern doublereal *scale;
extern doublereal *sumsq;
extern integer i__1;
extern integer i__2;
extern doublereal d__1;
extern integer ix;
extern doublereal absxi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp_sumsq = *sumsq;
    doublereal temp_scale = *scale;
    for (ix = 1; i__2 < 0 ? ix >= i__1 : ix <= i__1; ix += i__2) {
        if (x[ix] != 0.) {
            absxi = (d__1 = x[ix], ((d__1) >= 0 ? (d__1) : -(d__1)));
            if (temp_scale < absxi) {
                d__1 = temp_scale / absxi;
                temp_sumsq = temp_sumsq * (d__1 * d__1) + 1;
                temp_scale = absxi;
            } else {
                d__1 = absxi / temp_scale;
                temp_sumsq += d__1 * d__1;
            }
        }
    }
    *sumsq = temp_sumsq;
    *scale = temp_scale;
}
