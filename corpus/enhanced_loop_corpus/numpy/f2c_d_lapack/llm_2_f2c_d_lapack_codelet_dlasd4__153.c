#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *z__;
extern doublereal *delta;
extern doublereal *work;
extern integer i__1;
extern integer j;
extern doublereal phi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse, assuming n is even for correctness)
    // This modifies the access pattern to be strided by 2, still decrementing but skipping elements.
    integer stride = 2;
    for (j = ((*n % 2 == 0) ? *n : *n - 1); j >= i__1; j -= stride) {
        phi += z__[j] * z__[j] / (work[j] * delta[j]);
    }
}
