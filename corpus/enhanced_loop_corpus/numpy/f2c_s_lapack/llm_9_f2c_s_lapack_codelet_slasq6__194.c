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
    // Variant 2: Reduced computational intensity with simplified branching and fewer operations
    // Eliminate one branch by replacing conditional logic with fused arithmetic, reduce trip count by skipping every other iteration
    for (j4 = (*i0 << 2); j4 <= i__1; j4 += 8) { // Double step size to reduce trip count
        z__[j4 - 3] = d__ + z__[j4];

        // Replace conditional with direct computation using min/max-like safe division
        real denom = (z__[j4 - 3] != 0.F) ? z__[j4 - 3] : 1.F;
        real ratio = z__[j4 + 2] / denom;

        // Always compute scaled values without branching
        z__[j4 - 1] = z__[j4] * ratio;
        d__ = z__[j4 + 2] * (d__ / denom);

        // Update dmin and emin unconditionally
        *dmin__ = (doublereal)((*dmin__) <= (d__) ? (*dmin__) : (d__));
        emin = (doublereal)((emin <= z__[j4 - 1]) ? emin : z__[j4 - 1]);
    }
    // Note: This version sacrifices numerical safety (e.g., underflow checks via safmin) for speed and simplicity.
}
