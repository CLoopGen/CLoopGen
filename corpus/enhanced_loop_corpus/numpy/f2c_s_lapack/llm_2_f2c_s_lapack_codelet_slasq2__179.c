#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *z__;
extern integer i__1;
extern real r__1;
extern real r__2;
extern real d__;
extern integer k;
extern integer i0;
extern integer i4;
extern integer n0;
extern integer pp;
extern real tol2;
extern real emin;
extern real temp;
extern real qmax;
extern real safmin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 1; k <= 2; ++k) {
    d__ = z__[(n0 << 2) + pp - 3];
    i__1 = (i0 << 2) + pp;
    for (i4 = (n0 - 1 << 2) + pp; i4 >= i__1; i4 += -4) {
        if (z__[i4 - 1] <= tol2 * d__) {
            z__[i4 - 1] = -0.F;
            d__ = z__[i4 - 3];
        } else {
            d__ = z__[i4 - 3] * (d__ / (d__ + z__[i4 - 1]));
        }
    }
    emin = z__[(i0 << 2) + pp + 1];
    d__ = z__[(i0 << 2) + pp - 3];
    i__1 = (n0 - 1 << 2) + pp;
    for (i4 = (i0 << 2) + pp; i4 <= i__1; i4 += 4) {
        int idx1 = i4 - (pp << 1) - 2;
        int idx2 = i4 - 1;
        int idx3 = i4 + 1;
        z__[idx1] = d__ + z__[idx2];
        if (z__[idx2] <= tol2 * d__) {
            z__[idx2] = -0.F;
            z__[idx1] = d__;
            z__[idx1 + 2] = 0.F;
            d__ = z__[idx3];
        } else if (safmin * z__[idx3] < z__[idx1] && safmin * z__[idx1] < z__[idx3]) {
            temp = z__[idx3] / z__[idx1];
            z__[idx1 + 2] = z__[idx2] * temp;
            d__ *= temp;
        } else {
            z__[idx1 + 2] = z__[idx3] * (z__[idx2] / z__[idx1]);
            d__ = z__[idx3] * (d__ / z__[idx1]);
        }
        r__1 = emin , r__2 = z__[idx1 + 2];
        emin = (doublereal)((r__1) <= (r__2) ? (r__1) : (r__2));
    }
    z__[(n0 << 2) - pp - 2] = d__;
    qmax = z__[(i0 << 2) - pp - 2];
    i__1 = (n0 << 2) - pp - 2;
    for (i4 = (i0 << 2) - pp + 2; i4 <= i__1; i4 += 4) {
        r__1 = qmax , r__2 = z__[i4];
        qmax = (doublereal)((r__1) >= (r__2) ? (r__1) : (r__2));
    }
    pp = 1 - pp;
}
}
