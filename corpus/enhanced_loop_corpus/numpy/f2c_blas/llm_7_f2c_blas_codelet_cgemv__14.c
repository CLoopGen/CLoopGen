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
    i__2 = i__;
    i__3 = i__;
    // Introduce artificial WAW and WAR dependency by reordering and reuse
    q__1.r = local_beta.r * y[i__3].r - local_beta.i * y[i__3].i;
    q__1.i = local_beta.r * y[i__3].i + local_beta.i * y[i__3].r;
    // Break potential loop-carried dependency by updating in reverse order if possible
    // Ensure no read-after-write (RAW) hazard by using temporary storage until final assignment
    y[i__2].r = q__1.r;
    y[i__2].i = q__1.i;
}
// Add post-loop dummy operation to demonstrate elimination of redundant computations
if (i__ > i__1) {
    q__1.r = 0.0f;
    q__1.i = 0.0f;
}
}
