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
for (i__ = 1; i__ <= i__1; ++i__) {
    doublecomplex temp;
    i__2 = i__;
    i__3 = i__ + 1; // Introduce a read-ahead dependency (RAW) with bounds consideration
    if (i__3 <= i__1) { // Prevent out-of-bounds access
        z__1.r = beta->r * y[i__3].r - beta->i * y[i__3].i;
        z__1.i = beta->r * y[i__3].i + beta->i * y[i__3].r;
        temp.r = z__1.r;
        temp.i = z__1.i;
    } else {
        temp = y[i__]; // Fallback to current element if next is out of bounds
    }
    y[i__2].r = temp.r;
    y[i__2].i = temp.i;
}
}
