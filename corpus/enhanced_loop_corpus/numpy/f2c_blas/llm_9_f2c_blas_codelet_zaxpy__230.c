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
for (i__ = 1; i__ <= i__1; i__ += 2) {
    integer idx1 = i__;
    integer idx2 = i__ + 1;

    if (idx1 <= i__1) {
        z__2.r = za->r * zx[idx1].r - za->i * zx[idx1].i;
        z__2.i = za->r * zx[idx1].i + za->i * zx[idx1].r;
        z__1.r = zy[idx1].r + z__2.r;
        z__1.i = zy[idx1].i + z__2.i;
        zy[idx1].r = z__1.r;
        zy[idx1].i = z__1.i;
    }

    if (idx2 <= i__1) {
        z__2.r = za->r * zx[idx2].r - za->i * zx[idx2].i;
        z__2.i = za->r * zx[idx2].i + za->i * zx[idx2].r;
        z__1.r = zy[idx2].r + z__2.r;
        z__1.i = zy[idx2].i + z__2.i;
        zy[idx2].r = z__1.r;
        zy[idx2].i = z__1.i;
    }
}
}
