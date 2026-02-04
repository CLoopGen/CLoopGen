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

extern real *beta;
extern singlecomplex *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern real r__1;
extern singlecomplex q__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer base_idx;
singlecomplex *c_ptr;
for (j = 1; j <= i__1; ++j) {
    base_idx = j * c_dim1;
    c_ptr = &c__[base_idx];
    i__2 = j - 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        q__1.r = *beta * c_ptr[i__].r , q__1.i = *beta * c_ptr[i__].i;
        c__[i__ + base_idx].r = q__1.r , c__[i__ + base_idx].i = q__1.i;
    }
    r__1 = *beta * c_ptr[j].r;
    c__[base_idx + j].r = r__1 , c__[base_idx + j].i = 0.F;
}
}
