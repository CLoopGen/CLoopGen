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
for (integer outer = mid + bsiz2; outer <= i__1; ++outer) {
    for (k = outer; k <= outer; ++k) {
        z__[k] = 0.;
    }
}
}
