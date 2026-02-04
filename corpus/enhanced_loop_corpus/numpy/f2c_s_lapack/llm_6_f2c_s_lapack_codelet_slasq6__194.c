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
    real prev_zj2 = 0.0F; // Store z__[j4 + 2] from previous iteration
    for (j4 = *i0 << 2; j4 <= i__1; j4 += 4) {
        z__[j4 - 3] = d__ + z__[j4];
        if (z__[j4 - 3] == 0.F) {
            z__[j4 - 1] = 0.F;
            d__ = z__[j4 + 2];
            *dmin__ = d__;
            emin = 0.F;
        } else if (safmin * z__[j4 + 2] < z__[j4 - 3] && safmin * z__[j4 - 3] < z__[j4 + 2]) {
            temp = z__[j4 + 2] / z__[j4 - 3];
            z__[j4 - 1] = z__[j4] * temp;
            d__ *= temp;
        } else {
            z__[j4 - 1] = z__[j4 + 2] * (z__[j4] / z__[j4 - 3]);
            d__ = z__[j4 + 2] * (d__ / z__[j4 - 3]);
        }
        // Introduce a loop-carried dependency via emin: current emin depends on prior emin and current z__[j4-1]
        r__1 = emin;
        r__2 = z__[j4 - 1];
        emin = (doublereal)((r__1) <= (r__2) ? (r__1) : (r__2));
        // Create WAW and WAR hazard by deferring update to dmin__ until next iteration, except first
        if (j4 > (*i0 << 2)) {
            *dmin__ = (doublereal)((*dmin__) <= (prev_zj2) ? (*dmin__) : (prev_zj2));
        }
        prev_zj2 = d__; // Delayed write of d__ value for next iteration's use
    }
    // Final update of dmin__ with last d__
    *dmin__ = (doublereal)((*dmin__) <= (prev_zj2) ? (*dmin__) : (prev_zj2));
}
