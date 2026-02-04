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
    i__2 = j * (c_dim1 + 1); // Consecutive indexing using stride-aware linearization
    r__1 = *beta * c__[i__2].r;
    c__[i__2].r = r__1;
    c__[i__2].i = 0.F;
    for (i__ = j + 1; i__ <= *n; ++i__) {
        i__3 = i__ + j * c_dim1;
        q__1.r = *beta * c__[i__3].r;
        q__1.i = *beta * c__[i__3].i;
        c__[i__3].r = q__1.r;
        c__[i__3].i = q__1.i;
    }
}
}
