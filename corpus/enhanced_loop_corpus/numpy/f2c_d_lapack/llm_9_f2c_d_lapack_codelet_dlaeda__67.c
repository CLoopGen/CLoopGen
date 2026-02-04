#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *z__;
extern integer i__1;
extern integer k;
extern integer mid;
extern integer bsiz2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decreased computational intensity with expanded trip count but simpler operations
    // Trip count increased by starting earlier; each iteration only performs a conditional assignment
    integer start = (mid > 0) ? mid - bsiz2 : 0;
    for (k = start; k <= i__1; ++k) {
        z__[k] = (k >= mid + bsiz2) ? 0.0 : z__[k]; // Preserve old values below threshold, zero above
    }
}
