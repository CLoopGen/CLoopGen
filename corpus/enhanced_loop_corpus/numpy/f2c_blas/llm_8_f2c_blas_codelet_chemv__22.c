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
    singlecomplex local_beta;
    local_beta.r = beta->r;
    local_beta.i = beta->i;
    for (i__ = 1; i__ <= i__1; ++i__) {
        real yr = y[i__].r;
        real yi = y[i__].i;
        y[i__].r = local_beta.r * yr - local_beta.i * yi;
        y[i__].i = local_beta.r * yi + local_beta.i * yr;
    }
}
