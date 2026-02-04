#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *n;
extern singlecomplex *t;
extern singlecomplex *work;
extern integer t_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing t[i__ + i__ * t_dim1] which implies a strided access (like diagonal of a matrix),
    // we restructure to access consecutive elements in t, assuming t_dim1 is the leading dimension.
    // We'll traverse column-major order consecutively by fixing row index and varying column.
    integer base_idx = 1 + t_dim1; // Starting at t[1 + 1*t_dim1]
    for (i__ = 1; i__ <= i__1; ++i__) {
        work[i__ + *n].r = t[base_idx + (i__ - 1)].r;
        work[i__ + *n].i = t[base_idx + (i__ - 1)].i;
    }
}
