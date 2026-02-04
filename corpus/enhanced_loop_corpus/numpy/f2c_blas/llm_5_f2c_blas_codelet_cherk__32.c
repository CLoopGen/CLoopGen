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
for (j = 1; j <= i__1; ++j) {
    i__2 = j + j * c_dim1;
    i__3 = j + j * c_dim1;
    r__1 = *beta * c__[i__3].r;
    c__[i__2].r = r__1 , c__[i__2].i = 0.F;

    if (j > *n / 2) continue;

    i__2 = *n;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        if (i__ != j + 2) {
            i__3 = i__ + j * c_dim1;
            i__4 = i__ + j * c_dim1;
            q__1.r = *beta * c__[i__4].r , q__1.i = *beta * c__[i__4].i;
            c__[i__3].r = q__1.r , c__[i__3].i = q__1.i;
        }
    }
}
}
