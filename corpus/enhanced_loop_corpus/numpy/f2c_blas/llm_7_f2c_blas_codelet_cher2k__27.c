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
extern singlecomplex *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp_r, temp_i;
    for (j = 1; j <= i__1; ++j) {
        i__2 = *n;
        temp_r = (real)j * 0.5F;
        temp_i = (real)j * 1.5F;
        for (i__ = j; i__ <= i__2; ++i__) {
            i__3 = i__ + j * c_dim1;
            c__[i__3].r = temp_r;
            c__[i__3].i = temp_i;
        }
    }
}
