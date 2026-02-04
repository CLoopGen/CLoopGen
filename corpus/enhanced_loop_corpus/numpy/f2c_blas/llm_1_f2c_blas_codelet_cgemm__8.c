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

extern integer *m;
extern singlecomplex *beta;
extern singlecomplex *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1 && i__1 > 0; ++j) {
    i__2 = *m;
    if (i__2 > 0) {
        i__ = 1;
        i__3 = i__ + j * c_dim1;
        i__4 = i__ + j * c_dim1;
        q__1.r = beta->r * c__[i__4].r - beta->i * c__[i__4].i , q__1.i = beta->r * c__[i__4].i + beta->i * c__[i__4].r;
        c__[i__3].r = q__1.r , c__[i__3].i = q__1.i;
    }
}
}
