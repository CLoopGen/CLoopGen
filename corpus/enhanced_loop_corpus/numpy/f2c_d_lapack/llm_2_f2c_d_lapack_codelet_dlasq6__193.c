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
    // Instead of accessing z__[j4 - 2], z__[j4 - 1], z__[j4], z__[j4 + 1],
    // we reindex the loop to access elements in a consecutive, forward-striding manner.
    // We shift the base index to avoid negative offsets and ensure sequential progression.

    doublereal *z_ptr = &z__[*i0 << 2]; // Base pointer at j4 start
    integer offset = (*i0 << 2) - (*i0 << 2); // Normalize offset to zero for clarity
    integer stride = 4;
    integer normalized_count = (i__1 - (*i0 << 2)) / stride + 1;

    for (integer k = 0; k < normalized_count; ++k) {
        integer j4 = (*i0 << 2) + k * stride;
        doublereal *zp = z_ptr + k * stride;

        zp[2] = d__ + zp[3];  // z[j4 - 2] becomes zp[2] when base is shifted
        if (zp[2] == 0.) {
            zp[4] = 0.;
            d__ = zp[5];
            *dmin__ = d__;
            emin = 0.;
        } else if (safmin * zp[5] < zp[2] && safmin * zp[2] < zp[5]) {
            temp = zp[5] / zp[2];
            zp[4] = zp[3] * temp;
            d__ *= temp;
        } else {
            zp[4] = zp[5] * (zp[3] / zp[2]);
            d__ = zp[5] * (d__ / zp[2]);
        }
        *dmin__ = ((*dmin__) <= (d__) ? (*dmin__) : (d__));
        d__1 = emin , d__2 = zp[4];
        emin = ((d__1) <= (d__2) ? (d__1) : (d__2));
    }
}
