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
    integer unroll_factor = 2;
    integer bound = (i__1 - 1) / unroll_factor + 1;
    for (ix = 1; ix <= bound; ++ix) {
        integer base_idx = (ix - 1) * unroll_factor + 1;
        for (integer u = 0; u < unroll_factor; ++u) {
            integer current_ix = base_idx + u;
            if (i__2 < 0 ? current_ix >= i__1 : current_ix <= i__1) {
                if (x[current_ix] != 0.F) {
                    absxi = (r__1 = x[current_ix], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
                    if (*scale < absxi) {
                        r__1 = *scale / absxi;
                        *sumsq = *sumsq * (r__1 * r__1) + 1;
                        *scale = absxi;
                    } else {
                        r__1 = absxi / *scale;
                        *sumsq += r__1 * r__1;
                    }
                }
            }
        }
    }
}
