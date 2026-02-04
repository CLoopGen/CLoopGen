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

extern integer *ihi;
extern doublecomplex *tau;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublecomplex prev;
    prev.r = 0.0; prev.i = 0.0;
    for (i__ = ((1) >= (*ihi) ? (1) : (*ihi)); i__ <= i__1; ++i__) {
        i__2 = i__;
        // Create a loop-carried dependency: each iteration reads from previous write (RAW dependency)
        tau[i__2].r = prev.r + 1.0;
        tau[i__2].i = prev.i - 1.0;
        prev.r = tau[i__2].r;
        prev.i = tau[i__2].i;
    }
    // Eliminate original independent assignments; now each iteration depends on prior (loop-carried RAW)
}
