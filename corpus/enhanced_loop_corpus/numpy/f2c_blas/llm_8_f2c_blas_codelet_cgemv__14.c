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

extern singlecomplex *beta;
extern singlecomplex *y;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern singlecomplex q__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    if (i__ % 2 == 1) {
        i__2 = i__;
        i__3 = i__;
        q__1.r = beta->r * y[i__3].r - beta->i * y[i__3].i;
        q__1.i = beta->r * y[i__3].i + beta->i * y[i__3].r;
        y[i__2].r = q__1.r;
        y[i__2].i = q__1.i;
    }
}
}
