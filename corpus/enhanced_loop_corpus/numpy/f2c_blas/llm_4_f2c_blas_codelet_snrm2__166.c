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
    integer jx = (ix * 7) % (i__1 + 1); // Indirect access via hash-like index
    if (jx == 0) jx = 1;
    if (x[jx] != 0.F) {
        absxi = (r__1 = x[jx] , (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
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
