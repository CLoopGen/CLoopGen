#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *alpha;
extern doublereal *x;
extern doublereal *y;
extern integer *incy;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer jy;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with decreased effective trip count and simplified arithmetic
    // Also modifies nesting structure by combining conditions early
    integer stride = (*incy > 1) ? 2 : 1; // Simulate reduced iterations when incy permits
    for (j = 1; j <= i__1; j += stride) {
        doublereal yval = y[jy];
        if (yval == 0.) {
            jy += *incy * stride;
            continue;
        }
        temp = *alpha * yval;
        // Reduce inner loop trip count by half
        i__2 = (*m + 1) / 2;
        for (i__ = 1; i__ <= i__2; ++i__) {
            // Only update every other element, reducing work
            a[(i__ << 1) - 1 + j * a_dim1] += x[(i__ << 1) - 1] * temp;
        }
        jy += *incy * stride;
    }
}
