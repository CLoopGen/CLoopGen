#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *x;
extern real *scale;
extern real *sumsq;
extern integer i__1;
extern integer i__2;
extern real r__1;
extern integer ix;
extern real absxi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real local_scale = *scale;
    real accumulated_sumsq = 0.0F;
    for (ix = 1; i__2 < 0 ? ix >= i__1 : ix <= i__1; ix += i__2) {
        if (x[ix] != 0.F) {
            absxi = (r__1 = x[ix], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
            if (local_scale < absxi) {
                r__1 = local_scale / absxi;
                accumulated_sumsq = accumulated_sumsq * (r__1 * r__1) + 1;
                local_scale = absxi;
            } else {
                r__1 = absxi / local_scale;
                accumulated_sumsq += r__1 * r__1;
            }
        } else {
            // Introduce a dummy operation to maintain loop-carried dependency on accumulated_sumsq
            accumulated_sumsq += 0.0F;
        }
    }
    *sumsq += accumulated_sumsq;
}
