#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef double doublereal;

extern integer *i0;
extern real *z__;
extern real *dmin__;
extern integer i__1;
extern real r__1;
extern real r__2;
extern real d__;
extern integer j4;
extern real emin;
extern real temp;
extern real safmin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled and restructured for sequential z__ access)
    integer base;
    for (j4 = *i0 << 2; j4 <= i__1 - 4; j4 += 4) {
        base = j4 - 2;
        // Restructure accesses to z__ to be more consecutive: z__[base], z__[base+1], z__[base+2], z__[base+3]
        z__[base + 2] = d__ + z__[base + 1];
        if (z__[base + 2] == 0.F) {
            z__[base + 4] = 0.F;
            d__ = z__[base + 5];
            *dmin__ = d__;
            emin = 0.F;
        } else if (safmin * z__[base + 5] < z__[base + 2] && safmin * z__[base + 2] < z__[base + 5]) {
            temp = z__[base + 5] / z__[base + 2];
            z__[base + 4] = z__[base + 3] * temp;
            d__ *= temp;
        } else {
            z__[base + 4] = z__[base + 5] * (z__[base + 3] / z__[base + 2]);
            d__ = z__[base + 5] * (d__ / z__[base + 2]);
        }
        *dmin__ = (doublereal)((*dmin__) <= (d__) ? (*dmin__) : (d__));
        r__1 = emin, r__2 = z__[base + 4];
        emin = (doublereal)((r__1) <= (r__2) ? (r__1) : (r__2));
    }
    // Handle last iteration if needed (original bounds)
    if (j4 <= i__1) {
        z__[j4 - 2] = d__ + z__[j4 - 1];
        if (z__[j4 - 2] == 0.F) {
            z__[j4] = 0.F;
            d__ = z__[j4 + 1];
            *dmin__ = d__;
            emin = 0.F;
        } else if (safmin * z__[j4 + 1] < z__[j4 - 2] && safmin * z__[j4 - 2] < z__[j4 + 1]) {
            temp = z__[j4 + 1] / z__[j4 - 2];
            z__[j4] = z__[j4 - 1] * temp;
            d__ *= temp;
        } else {
            z__[j4] = z__[j4 + 1] * (z__[j4 - 1] / z__[j4 - 2]);
            d__ = z__[j4 + 1] * (d__ / z__[j4 - 2]);
        }
        *dmin__ = (doublereal)((*dmin__) <= (d__) ? (*dmin__) : (d__));
        r__1 = emin, r__2 = z__[j4];
        emin = (doublereal)((r__1) <= (r__2) ? (r__1) : (r__2));
    }
}
