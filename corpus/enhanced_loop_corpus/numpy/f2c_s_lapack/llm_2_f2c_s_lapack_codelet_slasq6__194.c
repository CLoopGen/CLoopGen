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
    // Variant 1: Consecutive Memory Access Pattern
    // Original strided access (every 4th element) is replaced with consecutive access.
    // We process elements sequentially starting from an offset derived from *i0.
    integer base = *i0 << 2;
    for (j4 = 0; j4 < i__1 - base + 1; j4 += 1) {
        integer idx = base + j4;
        z__[idx - 3] = d__ + z__[idx];
        if (z__[idx - 3] == 0.F) {
            z__[idx - 1] = 0.F;
            d__ = z__[idx + 2];
            *dmin__ = d__;
            emin = 0.F;
        } else if (safmin * z__[idx + 2] < z__[idx - 3] && safmin * z__[idx - 3] < z__[idx + 2]) {
            temp = z__[idx + 2] / z__[idx - 3];
            z__[idx - 1] = z__[idx] * temp;
            d__ *= temp;
        } else {
            z__[idx - 1] = z__[idx + 2] * (z__[idx] / z__[idx - 3]);
            d__ = z__[idx + 2] * (d__ / z__[idx - 3]);
        }
        *dmin__ = (doublereal)((*dmin__) <= (d__) ? (*dmin__) : (d__));
        r__1 = emin , r__2 = z__[idx - 1];
        emin = (doublereal)((r__1) <= (r__2) ? (r__1) : (r__2));
    }
}
