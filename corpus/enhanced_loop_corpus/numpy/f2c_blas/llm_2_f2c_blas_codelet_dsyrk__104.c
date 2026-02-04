#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *beta;
extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to strided access by unrolling and accessing every second element
    // This variant processes elements in a non-consecutive but predictable stride (stride of 2)
    for (j = 1; j <= i__1; ++j) {
        i__2 = j;
        // Process odd indices first with stride 2
        for (i__ = 1; i__ <= i__2; i__ += 2) {
            c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1];
        }
        // Then process even indices with stride 2
        for (i__ = 2; i__ <= i__2; i__ += 2) {
            c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1];
        }
    }
}
