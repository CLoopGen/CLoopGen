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
    for (k = mid + bsiz2; k <= i__1; ++k) {
        z__[k] = z__[k - 1]; // Introduce RAW dependency: current iteration reads previous write
    }
    if (mid + bsiz2 <= i__1) {
        z__[mid + bsiz2] = 0.; // Initialize first element to break dependency chain and preserve partial semantics
    }
}
