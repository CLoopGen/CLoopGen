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
    integer forward_ix;
    doublereal local_ssq = 1.0;
    doublereal local_scale = scale;
    for (forward_ix = 1; i__2 < 0 ? forward_ix >= i__1 : forward_ix <= i__1; forward_ix += i__2) {
        if (x[forward_ix] != 0.) {
            absxi = (d__1 = x[forward_ix], ((d__1) >= 0 ? (d__1) : -(d__1)));
            if (local_scale < absxi) {
                d__1 = local_scale / absxi;
                local_ssq = local_ssq * (d__1 * d__1);
                local_scale = absxi;
            } else {
                d__1 = absxi / local_scale;
                local_ssq += d__1 * d__1;
            }
        }
    }
    d__1 = local_scale / scale;
    ssq = ssq * (d__1 * d__1) + local_ssq - 1.0;
    scale = local_scale > scale ? local_scale : scale;
}
