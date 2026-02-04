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
if (mid + bsiz2 <= i__1) {
    k = mid + bsiz2;
    for (; k <= i__1; ++k) {
        z__[k] = 0.;
    }
} else {
    for (k = 1; k < 1; ++k) { // Empty loop body, no iterations
        z__[k] = 0.;
    }
}
}
