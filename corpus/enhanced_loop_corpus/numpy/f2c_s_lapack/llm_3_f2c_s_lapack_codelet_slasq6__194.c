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
    // Variant 2: Strided Access with Increased Stride and Offset Shift
    // Instead of stride 4, use a larger stride (e.g., 8), accessing fewer but more spread-out elements.
    // Also shift indexing to simulate different alignment patterns.
    for (j4 = (*i0 << 2); j4 <= i__1; j4 += 8) {  // Double the step: stride of 8
        // Use alternating offsets to create irregular yet deterministic pattern within stride
        integer offset = (j4 & 8) ? 0 : 4;  // Toggle between two positions within the block
        integer idx = j4 + offset;

        // Ensure index bounds are respected
        if (idx > i__1) break;

        z__[idx - 3] = d__ + z__[idx];
        if (z__[idx - 3] == 0.F) {
            z__[idx - 1] = 0.F;
            d__ = z__[idx + 2];
            *dmin__ = d__;
            emin = 0.F;
        } else if (safmin * z__[idx + 2] < z__[idx - 3] && safmin * z__[idx - 3] < z__[idx + 2]) {
            temp = z__[idx + 2] / z__[idx - 3];
            z__[idx - 1] = z__[idx] * temp;
            d__ *= temp;
        } else {
            z__[idx - 1] = z__[idx + 2] * (z__[idx] / z__[idx - 3]);
            d__ = z__[idx + 2] * (d__ / z__[idx - 3]);
        }
        *dmin__ = (doublereal)((*dmin__) <= (d__) ? (*dmin__) : (d__));
        r__1 = emin , r__2 = z__[idx - 1];
        emin = (doublereal)((r__1) <= (r__2) ? (r__1) : (r__2));
    }
}
