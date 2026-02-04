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
for (j = 1; j <= i__1 && j <= *n; j += 2) {
    for (i__ = j; i__ <= *n; ++i__) {
        integer idx1 = i__ + j * c_dim1;
        real temp_r = c__[idx1].r;
        real temp_i = c__[idx1].i;
        c__[idx1].r = *beta * temp_r;
        c__[idx1].i = *beta * temp_i;
    }

    if (j + 1 <= i__1) {
        ++j;
        for (i__ = j; i__ <= *n; ++i__) {
            integer idx2 = i__ + j * c_dim1;
            c__[idx2].r = *beta * c__[idx2].r;
            c__[idx2].i = *beta * c__[idx2].i;
        }
    }
}
}
