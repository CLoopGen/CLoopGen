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
    // Variant 1: Consecutive Memory Access Pattern
    // Original strided access (every 4th element starting from j4-3) is transformed into consecutive writes
    // by reorganizing the indexing logic to traverse z__ in a forward sequential manner.
    integer base = *i0 << 2;
    for (j4 = 0; j4 <= (i__1 - base); j4 += 4) {
        integer idx = base + j4;
        z__[idx - 3] = d__ + z__[idx];
        if (z__[idx - 3] == 0.) {
            z__[idx - 1] = 0.;
            d__ = z__[idx + 2];
            *dmin__ = d__;
            emin = 0.;
        } else if (safmin * z__[idx + 2] < z__[idx - 3] && safmin * z__[idx - 3] < z__[idx + 2]) {
            doublereal temp = z__[idx + 2] / z__[idx - 3];
            z__[idx - 1] = z__[idx] * temp;
            d__ *= temp;
        } else {
            z__[idx - 1] = z__[idx + 2] * (z__[idx] / z__[idx - 3]);
            d__ = z__[idx + 2] * (d__ / z__[idx - 3]);
        }
        *dmin__ = ((*dmin__) <= (d__) ? (*dmin__) : (d__));
        d__1 = emin;
        d__2 = z__[idx - 1];
        emin = ((d__1) <= (d__2) ? (d__1) : (d__2));
    }
}
