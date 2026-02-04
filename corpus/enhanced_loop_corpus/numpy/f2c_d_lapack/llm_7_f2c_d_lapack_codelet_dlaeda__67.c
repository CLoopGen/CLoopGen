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
    integer step = 2;
    // Split loop into two passes to eliminate loop-carried dependencies and enable parallelism
    for (k = mid + bsiz2; k <= i__1; k += step) {
        z__[k] = 0.; // Remove any potential WAW or WAR hazards by independent writes
    }
    for (k = mid + bsiz2 + 1; k <= i__1; k += step) {
        z__[k] = 0.;
    }
}
