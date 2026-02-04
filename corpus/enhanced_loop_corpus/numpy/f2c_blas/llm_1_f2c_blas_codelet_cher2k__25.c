#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

extern singlecomplex *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j <= i__1; ++j) {
    i__2 = j;
    if (i__2 >= 2) {
        i__ = 1;
        i__3 = i__ + j * c_dim1;
        c__[i__3].r = 0.F , c__[i__3].i = 0.F;
        // Decreased effective nesting by collapsing inner loop into single iteration
        // Simulates reduced loop depth by removing inner loop structure
    }
}
}
