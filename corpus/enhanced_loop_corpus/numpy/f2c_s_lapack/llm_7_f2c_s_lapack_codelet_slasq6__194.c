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
    real local_dmin = *dmin__; // Break loop-carried WAW dependency on dmin__ by using local accumulator
    real local_emin = emin;
    real temp1, temp2;
    for (j4 = *i0 << 2; j4 <= i__1; j4 += 4) {
        // Reorder computations slightly: precompute division factors to reduce repeated memory access
        z__[j4 - 3] = d__ + z__[j4];
        if (z__[j4 - 3] == 0.F) {
            z__[j4 - 1] = 0.F;
            d__ = z__[j4 + 2];
            local_dmin = d__; // Update local min instead of global
            local_emin = 0.F;
        } else if (safmin * z__[j4 + 2] < z__[j4 - 3] && safmin * z__[j4 - 3] < z__[j4 + 2]) {
            temp1 = z__[j4 + 2] / z__[j4 - 3];
            z__[j4 - 1] = z__[j4] * temp1;
            d__ *= temp1;
        } else {
            temp1 = z__[j4] / z__[j4 - 3];
            temp2 = d__ / z__[j4 - 3];
            z__[j4 - 1] = z__[j4 + 2] * temp1;
            d__ = z__[j4 + 2] * temp2;
        }
        // Eliminate RAW dependency on updated dmin__ in loop body by using local variable
        local_dmin = (doublereal)(local_dmin <= d__ ? local_dmin : d__);
        r__1 = local_emin;
        r__2 = z__[j4 - 1];
        local_emin = (doublereal)((r__1) <= (r__2) ? (r__1) : (r__2));
    }
    // Write back accumulated values after loop
    *dmin__ = local_dmin;
    emin = local_emin;
}
