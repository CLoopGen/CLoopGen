#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

extern integer *n;
extern doublereal *beta;
extern doublecomplex *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern doublereal d__1;
extern doublecomplex z__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    if (j % 2 == 0) {
        i__2 = j + j * c_dim1;
        i__3 = j + j * c_dim1;
        d__1 = *beta * c__[i__3].r;
        c__[i__2].r = d__1 , c__[i__2].i = 0.;
    } else {
        i__2 = j + j * c_dim1;
        c__[i__2].r = 0.0;
        c__[i__2].i = 0.0;
    }
    i__2 = *n;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * c_dim1;
        i__4 = i__ + j * c_dim1;
        z__1.r = *beta * c__[i__4].r , z__1.i = *beta * c__[i__4].i;
        c__[i__3].r = z__1.r , c__[i__3].i = z__1.i;
    }
}
}
