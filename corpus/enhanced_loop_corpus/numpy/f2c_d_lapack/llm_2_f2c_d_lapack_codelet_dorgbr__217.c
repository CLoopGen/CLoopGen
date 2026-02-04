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
    // Variant 1: Consecutive memory access by flattening the 2D index into a 1D pattern
    // Assuming row-major order and that a is effectively a 1D array representing a matrix
    // We change access from a[i__ + a_dim1] to writing to consecutive locations starting from a[2 + a_dim1]
    integer base_index = 2 + a_dim1;
    for (i__ = 0; i__ <= i__1 - 2; ++i__) {
        a[base_index + i__] = 0.;
    }
}
