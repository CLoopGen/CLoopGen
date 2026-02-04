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
    // Variant 1: Consecutive memory access by unrolling the loop with stride of 2
    integer start = (2 % 2 == 0) ? 2 : 3;
    for (i__ = start; i__ <= i__1 - 1; i__ += 2) {
        a[i__     + a_dim1] = 0.;
        a[i__ + 1 + a_dim1] = 0.;
    }
    // Handle odd-sized range if needed
    if (i__ <= i__1) {
        a[i__ + a_dim1] = 0.;
    }
}
