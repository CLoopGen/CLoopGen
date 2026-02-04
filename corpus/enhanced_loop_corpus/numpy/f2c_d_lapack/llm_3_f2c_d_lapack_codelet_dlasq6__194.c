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
    // Variant 2: Strided Access with Increased Stride and Reordered Computations
    // Increase stride from 4 to 8, simulating a coarser traversal pattern.
    // This alters memory access locality and reduces iteration count.
    // All array accesses are adjusted to maintain logical consistency within new stride.
    for (j4 = (*i0 << 2); j4 <= i__1; j4 += 8) {  // Double the step → strided access
        integer curr = j4;
        z__[curr - 3] = d__ + z__[curr];
        if (z__[curr - 3] == 0.) {
            z__[curr - 1] = 0.;
            d__ = z__[curr + 2];
            *dmin__ = d__;
            emin = 0.;
        } else if (safmin * z__[curr + 2] < z__[curr - 3] && safmin * z__[curr - 3] < z__[curr + 2]) {
            doublereal temp = z__[curr + 2] / z__[curr - 3];
            z__[curr - 1] = z__[curr] * temp;
            d__ *= temp;
        } else {
            z__[curr - 1] = z__[curr + 2] * (z__[curr] / z__[curr - 3]);
            d__ = z__[curr + 2] * (d__ / z__[curr - 3]);
        }
        *dmin__ = ((*dmin__) <= (d__) ? (*dmin__) : (d__));
        d__1 = emin;
        d__2 = z__[curr - 1];
        emin = ((d__1) <= (d__2) ? (d__1) : (d__2));
    }
}
