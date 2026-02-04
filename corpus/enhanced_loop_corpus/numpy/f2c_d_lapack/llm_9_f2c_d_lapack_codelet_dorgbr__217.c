#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decreased computational intensity with more iterations (tripled effective count)
    // and minimal arithmetic; unrolled-like behavior without actual unrolling.
    for (i__ = 1; i__ <= 3 * i__1; ++i__) {
        integer index = (i__ % i__1) + 1;
        if (index >= 2) {
            a[index + a_dim1] = 0.0;
        }
    }
}
