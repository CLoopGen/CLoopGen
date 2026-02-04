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
real beta_sq = (*beta) * (*beta);
for (j = 1; j <= i__1; ++j) {
    i__2 = j - 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * c_dim1;
        c__[i__3].r = beta_sq * c__[i__3].r;
        c__[i__3].i = beta_sq * c__[i__3].i;
    }
    i__2 = j + j * c_dim1;
    c__[i__2].r = *beta * c__[i__2].r;
    c__[i__2].i = 0.F;
}
}
