#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern integer i__1;
extern integer k;
extern integer mid;
extern integer bsiz2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element)
    for (k = mid + bsiz2; k <= i__1; k += 2) {
        z__[k] = 0.F;
    }
    // Handle potential odd-indexed last element if stride skips it
    if ((i__1 - (mid + bsiz2)) % 2 != 0 && i__1 >= mid + bsiz2) {
        z__[i__1] = 0.F;
    }
}
