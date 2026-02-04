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
    for (j = 1; j <= i__1; ++j) {
        i__2 = j;
        real accumulator_r = 0.F, accumulator_i = 0.F;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__ + j * c_dim1;
            accumulator_r += c__[i__3].r;
            accumulator_i += c__[i__3].i;
            c__[i__3].r = 0.F;
            c__[i__3].i = 0.F;
        }
        if (j > 1) {
            i__3 = 1 + j * c_dim1;
            c__[i__3].r = accumulator_r;
            c__[i__3].i = accumulator_i;
        }
    }
}
