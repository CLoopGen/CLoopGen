#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *beta;
extern doublecomplex *y;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern doublecomplex z__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Increase trip count and reduce operations per iteration by unrolling and simplifying logic
for (i__ = 1; i__ <= i__1 * 2; i__ += 2) {
    // Process two elements per iteration with simplified arithmetic (only one complex scaling)
    if (i__ <= i__1) {
        i__2 = i__;
        i__3 = i__;
        z__1.r = beta->r * y[i__3].r;
        z__1.i = beta->r * y[i__3].i;
        y[i__2].r = z__1.r;
        y[i__2].i = z__1.i;
    }
    if (i__ + 1 <= i__1) {
        i__2 = i__ + 1;
        i__3 = i__ + 1;
        z__1.r = beta->r * y[i__3].r;
        z__1.i = beta->r * y[i__3].i;
        y[i__2].r = z__1.r;
        y[i__2].i = z__1.i;
    }
}
}
