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
extern integer *incy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern doublecomplex z__1;
extern integer i__;
extern integer iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Consecutive memory access by precomputing indices into a temporary array-like traversal
integer base_idx = iy;
for (i__ = 0; i__ < i__1; ++i__) {
    integer curr = base_idx + i__; // Consecutive access starting from iy
    i__2 = curr;
    i__3 = curr;
    z__1.r = beta->r * y[i__3].r - beta->i * y[i__3].i;
    z__1.i = beta->r * y[i__3].i + beta->i * y[i__3].r;
    y[i__2].r = z__1.r;
    y[i__2].i = z__1.i;
}
}
