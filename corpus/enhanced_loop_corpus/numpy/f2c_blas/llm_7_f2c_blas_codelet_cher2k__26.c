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
real beta_val = *beta;
for (j = 1; j <= i__1; ++j) {
    singlecomplex temp;
    i__2 = j - 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * c_dim1;
        temp.r = beta_val * c__[i__3].r;
        temp.i = beta_val * c__[i__3].i;
        c__[i__3].r = temp.r;
        c__[i__3].i = temp.i;
    }
    i__2 = j + j * c_dim1;
    c__[i__2].r = beta_val * c__[i__2].r;
    c__[i__2].i = 0.F;
}
}
