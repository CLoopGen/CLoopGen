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
    integer temp_ix;
    doublereal temp_absxi, temp_scale = scale;
    doublereal temp_ssq = ssq;
    for (ix = 1; i__2 < 0 ? ix >= i__1 : ix <= i__1; ix += i__2) {
        temp_ix = ix;
        if (x[temp_ix] != 0.) {
            temp_absxi = (d__1 = x[temp_ix], ((d__1) >= 0 ? (d__1) : -(d__1)));
            if (temp_scale < temp_absxi) {
                d__1 = temp_scale / temp_absxi;
                temp_ssq = temp_ssq * (d__1 * d__1) + 1.;
                temp_scale = temp_absxi;
            } else {
                d__1 = temp_absxi / temp_scale;
                temp_ssq += d__1 * d__1;
            }
        }
    }
    scale = temp_scale;
    ssq = temp_ssq;
}
