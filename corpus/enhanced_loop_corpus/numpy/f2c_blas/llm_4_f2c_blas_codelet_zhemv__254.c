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
    if (i__ % 2 == 0) {
        i__2 = i__;
        i__3 = i__;
        z__1.r = beta->r * y[i__3].r - beta->i * y[i__3].i;
        z__1.i = beta->r * y[i__3].i + beta->i * y[i__3].r;
        y[i__2].r = z__1.r;
        y[i__2].i = z__1.i;
    } else {
        i__2 = i__;
        y[i__2].r = 0.0;
        y[i__2].i = 0.0;
    }
}
}
