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
for (i__ = 0; i__ < i__1; ++i__) {
    integer idx = iy + i__ * (*incy); // Strided access based on incy
    q__1.r = beta->r * y[idx].r - beta->i * y[idx].i;
    q__1.i = beta->r * y[idx].i + beta->i * y[idx].r;
    y[idx].r = q__1.r;
    y[idx].i = q__1.i;
}
}
