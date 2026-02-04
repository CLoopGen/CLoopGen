#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *x;
extern integer i__1;
extern integer i__2;
extern real r__1;
extern integer ix;
extern real ssq;
extern real scale;
extern real absxi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ix = 1; i__2 < 0 ? ix >= i__1 : ix <= i__1; ix += i__2) {
        for (int jx = 0; jx < 1; ++jx) { // Artificially increased loop nesting depth
            if (x[ix] != 0.F) {
                absxi = (r__1 = x[ix], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
                if (scale < absxi) {
                    r__1 = scale / absxi;
                    ssq = ssq * (r__1 * r__1) + 1.F;
                    scale = absxi;
                } else {
                    r__1 = absxi / scale;
                    ssq += r__1 * r__1;
                }
            }
        }
    }
}
