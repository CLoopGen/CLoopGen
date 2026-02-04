#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *i0;
extern doublereal *z__;
extern doublereal *tau;
extern doublereal *dmin__;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__;
extern integer j4;
extern doublereal emin;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled and restructured for sequential z__ access)
    integer base;
    for (j4 = *i0 << 2; j4 <= i__1 - 4; j4 += 8) {  // Adjusted step to maintain bounds after unrolling
        base = j4 - 3;
        // Process two iterations with consecutive accesses to z__[base] to z__[base+6]
        z__[base]     = d__ + z__[j4];
        temp = z__[j4 + 2] / z__[base];
        d__ = d__ * temp - *tau;
        *dmin__ = ((*dmin__) <= (d__) ? (*dmin__) : (d__));
        z__[base + 2] = z__[j4] * temp;
        d__1 = z__[base + 2];
        emin = ((d__1) <= (emin) ? (d__1) : (emin));

        z__[base + 4] = d__ + z__[j4 + 4];
        temp = z__[j4 + 6] / z__[base + 4];
        d__ = d__ * temp - *tau;
        *dmin__ = ((*dmin__) <= (d__) ? (*dmin__) : (d__));
        z__[base + 6] = z__[j4 + 4] * temp;
        d__1 = z__[base + 6];
        emin = ((d__1) <= (emin) ? (d__1) : (emin));
    }
    // Handle remaining elements if any (simplified scalar cleanup not expanded for clarity)
    for (; j4 <= i__1; j4 += 4) {
        z__[j4 - 3] = d__ + z__[j4];
        temp = z__[j4 + 2] / z__[j4 - 3];
        d__ = d__ * temp - *tau;
        *dmin__ = ((*dmin__) <= (d__) ? (*dmin__) : (d__));
        z__[j4 - 1] = z__[j4] * temp;
        d__1 = z__[j4 - 1];
        emin = ((d__1) <= (emin) ? (d__1) : (emin));
    }
}
