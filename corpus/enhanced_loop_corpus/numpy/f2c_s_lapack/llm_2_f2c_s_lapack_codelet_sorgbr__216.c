#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling the loop with stride of 2
    // This accesses elements in a strided pattern but processes two iterations per loop cycle
    integer i__;
    for (i__ = 2; i__ <= i__1 - 1; i__ += 2) {
        a[i__     + a_dim1] = 0.F;
        a[i__ + 1 + a_dim1] = 0.F;
    }
    // Handle remaining element if i__1 is odd
    if (i__ <= i__1) {
        a[i__ + a_dim1] = 0.F;
    }
}
