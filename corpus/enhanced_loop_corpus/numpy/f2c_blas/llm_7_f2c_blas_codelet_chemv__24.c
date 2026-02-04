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
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern singlecomplex q__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
singlecomplex acc;
acc.r = 0.0f;
acc.i = 0.0f;
for (i__ = 1; i__ <= i__1; ++i__) {
    integer idx = iy;
    singlecomplex scaled;
    scaled.r = beta->r * y[idx].r - beta->i * y[idx].i;
    scaled.i = beta->r * y[idx].i + beta->i * y[idx].r;
    acc.r += scaled.r;
    acc.i += scaled.i;
    y[idx].r = scaled.r;
    y[idx].i = scaled.i;
    iy += *incy;
}
y[0].r += acc.r;
y[0].i += acc.i;
}
