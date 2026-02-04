#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *i0;
extern doublereal *z__;
extern doublereal *dmin__;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern doublereal d__;
extern integer j4;
extern doublereal emin;
extern doublereal temp;
extern doublereal safmin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced arithmetic complexity with simplified branching and increased trip frequency
    for (j4 = *i0 << 2; j4 <= i__1; j4 += 2) {  // Halve the step to double iterations, simpler logic
        // Simplified computation: remove division-heavy branch, use only additive updates
        z__[j4 - 3] = d__ + z__[j4];

        // Replace complex conditional with a single safe update to minimize divisions
        if (z__[j4 - 3] != 0.0 && z__[j4 + 2] > safmin * z__[j4 - 3]) {
            temp = z__[j4 + 2] / z__[j4 - 3];
            z__[j4 - 1] = z__[j4] * temp;
            d__ *= temp;
        } else {
            // Fallback to minimal computation instead of full rational expression
            z__[j4 - 1] = z__[j4];  // Avoid division by zero or underflow
            if (z__[j4 - 3] == 0.0) {
                d__ = z__[j4 + 2];
            }
        }

        // Update dmin__ and emin unconditionally with simplified expressions
        *dmin__ = (*dmin__ < d__) ? *dmin__ : d__;
        emin = (emin < z__[j4 - 1]) ? emin : z__[j4 - 1];
    }
}
