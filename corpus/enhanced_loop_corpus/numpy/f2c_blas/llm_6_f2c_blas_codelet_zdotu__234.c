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
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;
extern doublecomplex ztemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        if (zx[i__].r > 0.0 || zy[i__].i < 0.0) {
            i__2 = i__;
            i__3 = i__;
            z__2.r = zx[i__2].r * zy[i__3].r - zx[i__2].i * zy[i__3].i;
            z__2.i = zx[i__2].r * zy[i__3].i + zx[i__2].i * zy[i__3].r;
            z__1.r = ztemp.r + z__2.r;
            z__1.i = ztemp.i + z__2.i;
            ztemp.r = z__1.r;
            ztemp.i = z__1.i;
        } else {
            z__1.r = ztemp.r * 1.05;
            z__1.i = ztemp.i * 1.05;
            ztemp.r = z__1.r;
            ztemp.i = z__1.i;
        }
    }
}
