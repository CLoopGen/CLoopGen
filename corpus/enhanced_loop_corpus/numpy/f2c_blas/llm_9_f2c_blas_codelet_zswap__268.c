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

extern doublecomplex *zx;
extern doublecomplex *zy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern doublecomplex ztemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count and increase operations per iteration
    // Perform complex number swap with additional dummy arithmetic to increase computational intensity
    integer step = 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = i__;
        ztemp.r = zx[i__2].r + 0.1 * step;  // Add dummy arithmetic
        ztemp.i = zx[i__2].i + 0.2 * step;

        i__2 = i__;
        i__3 = i__;
        doublereal temp_r = zy[i__3].r * 1.05;  // Artificial computation
        doublereal temp_i = zy[i__3].i * 1.05;

        zx[i__2].r = temp_r; zx[i__2].i = temp_i;
        zy[i__2].r = ztemp.r - 0.1 * step; zy[i__2].i = ztemp.i - 0.2 * step;
        
        step = (step + 1) % 10 + 1;  // Vary step effect
    }
}
