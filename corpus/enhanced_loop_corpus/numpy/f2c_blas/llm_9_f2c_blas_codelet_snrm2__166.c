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
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    integer step = i__2 * 2;  // Double the increment to reduce trip count by ~2x
    integer bound = (i__2 < 0) ? ((ix >= i__1 - 1) ? i__1 - 1 : i__1) : ((ix <= i__1 - 1) ? i__1 - 1 : i__1);
    for (ix = 1; i__2 < 0 ? ix >= bound : ix <= bound; ix += step) {
        real sum_abs = 0.0F;
        // Process two elements per iteration if within bounds
        if (x[ix] != 0.F) {
            absxi = (r__1 = x[ix], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
            sum_abs += absxi;
            if (scale < absxi) {
                r__1 = scale / absxi;
                ssq = ssq * (r__1 * r__1) + 1.F;
                scale = absxi;
            } else {
                r__1 = absxi / scale;
                ssq += r__1 * r__1;
            }
        }
        integer ix2 = ix + i__2;  // Next index in original sequence
        if ((i__2 < 0 ? ix2 >= i__1 : ix2 <= i__1) && x[ix2] != 0.F) {
            absxi = (r__1 = x[ix2], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
            sum_abs += absxi;
            if (scale < absxi) {
                r__1 = scale / absxi;
                ssq = ssq * (r__1 * r__1) + 1.F;
                scale = absxi;
            } else {
                r__1 = absxi / scale;
                ssq += r__1 * r__1;
            }
        }
        // Additional computation to increase arithmetic intensity
        if (sum_abs > 0.0F) {
            sum_abs = sum_abs * 0.5F + 0.1F;
            ssq += (real)(sum_abs / (doublereal)scale);
        }
    }
}
