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
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    // The loop now runs every 2nd iteration and performs multiple arithmetic assignments per element
    for (k = mid + bsiz2; k <= i__1; k += 2) {
        z__[k] = (doublereal)(k - mid) * 0.5;
        if (k + 1 <= i__1) {
            z__[k + 1] = (doublereal)(mid + bsiz2 - k) * 0.25;
        }
    }
}
