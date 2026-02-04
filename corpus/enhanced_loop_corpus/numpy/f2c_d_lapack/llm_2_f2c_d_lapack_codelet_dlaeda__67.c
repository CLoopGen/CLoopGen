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
    // Variant 1: Strided memory access with stride of 2
    for (k = mid + bsiz2; k <= i__1; k += 2) {
        z__[k] = 0.;
    }
    // Handle any potential odd-indexed element if range includes an odd number of elements
    if ((i__1 - (mid + bsiz2)) % 2 == 0 && (mid + bsiz2) <= i__1) {
        z__[i__1] = 0.;
    }
}
