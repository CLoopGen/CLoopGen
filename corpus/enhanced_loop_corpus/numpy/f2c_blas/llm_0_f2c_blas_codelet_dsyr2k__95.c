#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to consecutive by swapping loop order
    // This accesses c__ in column-major consecutive order (assuming Fortran-style layout)
    for (i__ = 1; i__ <= i__1; ++i__) {
        for (j = i__; j <= i__1; ++j) {
            c__[i__ + j * c_dim1] = 0.;
        }
    }
}
