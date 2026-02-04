#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern doublereal d__;
extern integer k;
extern integer i0;
extern integer i4;
extern integer n0;
extern integer pp;
extern doublereal tol2;
extern doublereal emin;
extern doublereal temp;
extern doublereal qmax;
extern doublereal safmin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 1; k <= 2; ++k) {
    d__ = z__[(n0 << 2) + pp - 3];
    i__1 = (i0 << 2) + pp;
    for (i4 = (n0 - 1 << 2) + pp; i4 >= i__1; i4 += -4) {
        if (z__[i4 - 1] > tol2 * d__) {
            d__ = z__[i4 - 3] * (d__ / (d__ + z__[i4 - 1]));
        } else {
            z__[i4 - 1] = -0.;
            d__ = z__[i4 - 3];
        }
    }
    emin = z__[(i0 << 2) + pp + 1];
    d__ = z__[(i0 << 2) + pp - 3];
    i__1 = (n0 - 1 << 2) + pp;
    for (i4 = (i0 << 2) + pp; i4 <= i__1; i4 += 4) {
        z__[i4 - (pp << 1) - 2] = d__ + z__[i4 - 1];
        if (z__[i4 - 1] <= tol2 * d__) {
            z__[i4 - 1] = -0.;
            z__[i4 - (pp << 1) - 2] = d__;
            z__[i4 - (pp << 1)] = 0.;
            d__ = z__[i4 + 1];
        } else if (safmin * z__[i4 + 1] < z__[i4 - (pp << 1) - 2]) {
            temp = z__[i4 + 1] / z__[i4 - (pp << 1) - 2];
            z__[i4 - (pp << 1)] = z__[i4 - 1] * temp;
            d__ *= temp;
        } else {
            z__[i4 - (pp << 1)] = z__[i4 + 1] * (z__[i4 - 1] / z__[i4 - (pp << 1) - 2]);
            d__ = z__[i4 + 1] * (d__ / z__[i4 - (pp << 1) - 2]);
        }
        if (z__[i4 - (pp << 1)] < emin) {
            emin = z__[i4 - (pp << 1)];
        }
    }
    z__[(n0 << 2) - pp - 2] = d__;
    qmax = z__[(i0 << 2) - pp - 2];
    i__1 = (n0 << 2) - pp - 2;
    for (i4 = (i0 << 2) - pp + 2; i4 <= i__1; i4 += 4) {
        if (z__[i4] > qmax) {
            qmax = z__[i4];
        }
    }
    pp = 1 - pp;
}
}
