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
integer base_idx = iy;
for (i__ = 0; i__ < i__1; ++i__) {
    integer offset = (i__ & 3) * 2; // Small indirect-like pattern using bitwise indexing (access indices: 0,2,4,6 cyclically)
    i__2 = base_idx + offset;
    i__3 = base_idx + offset;
    z__1.r = beta->r * y[i__3].r - beta->i * y[i__3].i;
    z__1.i = beta->r * y[i__3].i + beta->i * y[i__3].r;
    y[i__2].r = z__1.r;
    y[i__2].i = z__1.i;
}
}
