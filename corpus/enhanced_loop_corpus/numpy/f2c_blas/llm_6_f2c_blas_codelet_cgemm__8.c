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
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * c_dim1;
        i__4 = i__ + (j - 1) * c_dim1; // Modified index to create a loop-carried dependency on previous j iteration
        if (j > 1) {
            q__1.r = beta->r * c__[i__4].r - beta->i * c__[i__4].i;
            q__1.i = beta->r * c__[i__4].i + beta->i * c__[i__4].r;
        } else {
            q__1.r = c__[i__3].r;
            q__1.i = c__[i__3].i;
        }
        c__[i__3].r = q__1.r;
        c__[i__3].i = q__1.i;
    }
}
}
