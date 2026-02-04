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

extern doublecomplex *za;
extern doublecomplex *zx;
extern doublecomplex *zy;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
doublecomplex accumulator = {0.0, 0.0};
for (i__ = 1; i__ <= i__1; ++i__) {
    i__2 = i__;
    i__3 = i__;
    i__4 = i__;
    z__2.r = za->r * zx[i__4].r - za->i * zx[i__4].i;
    z__2.i = za->r * zx[i__4].i + za->i * zx[i__4].r;
    accumulator.r += zy[i__3].r + z__2.r;
    accumulator.i += zy[i__3].i + z__2.i;
}
// Introduce a WAW dependency by writing final result after loop
for (i__ = 1; i__ <= i__1; ++i__) {
    zy[i__].r = accumulator.r / i__1;
    zy[i__].i = accumulator.i / i__1;
}
}
