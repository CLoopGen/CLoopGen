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
    // Variant 2: Strided Access with Reverse Iteration
    // Modify memory access pattern by iterating backward with same stride,
    // changing spatial locality and potentially affecting cache behavior.
    // The array accesses remain strided but now traverse from high to low indices.

    integer start = *i0 << 2;
    integer end = i__1;
    integer step = 4;

    // Adjust start to align with last multiple of 4 <= i__1
    integer j4 = end - ((end - start) % step);

    for (; j4 >= start; j4 -= step) {
        z__[j4 - 2] = d__ + z__[j4 - 1];
        if (z__[j4 - 2] == 0.) {
            z__[j4] = 0.;
            d__ = z__[j4 + 1];
            *dmin__ = d__;
            emin = 0.;
        } else if (safmin * z__[j4 + 1] < z__[j4 - 2] && safmin * z__[j4 - 2] < z__[j4 + 1]) {
            temp = z__[j4 + 1] / z__[j4 - 2];
            z__[j4] = z__[j4 - 1] * temp;
            d__ *= temp;
        } else {
            z__[j4] = z__[j4 + 1] * (z__[j4 - 1] / z__[j4 - 2]);
            d__ = z__[j4 + 1] * (d__ / z__[j4 - 2]);
        }
        *dmin__ = ((*dmin__) <= (d__) ? (*dmin__) : (d__));
        d__1 = emin , d__2 = z__[j4];
        emin = ((d__1) <= (d__2) ? (d__1) : (d__2));
    }
}
