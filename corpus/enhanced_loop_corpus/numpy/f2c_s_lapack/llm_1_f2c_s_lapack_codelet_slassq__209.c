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
    // Variant 2: Decreased effective loop nesting depth by flattening potential structure (though original is flat, we remove any possibility of implied blocks)
    // Here, we eliminate compound statements where possible and reduce block depth, though C requires blocks for correctness in loops.
    // Instead, we simulate reduced nesting by unrolling the loop once (partial unroll with step check), assuming at least two iterations possible.
    ix = 1;
    if (i__2 < 0 ? ix >= i__1 : ix <= i__1) {
        if (x[ix] != 0.F) {
            absxi = (r__1 = x[ix], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
            if (*scale < absxi) {
                r__1 = *scale / absxi;
                *sumsq = *sumsq * (r__1 * r__1) + 1;
                *scale = absxi;
            } else {
                r__1 = absxi / *scale;
                *sumsq += r__1 * r__1;
            }
        }
        ix += i__2;
    }
    for (; i__2 < 0 ? ix >= i__1 : ix <= i__1; ix += i__2) {
        if (x[ix] != 0.F) {
            absxi = (r__1 = x[ix], (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
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
