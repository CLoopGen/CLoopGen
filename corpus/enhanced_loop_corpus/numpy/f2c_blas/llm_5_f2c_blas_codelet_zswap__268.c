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
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = i__;
        ztemp.r = zx[i__2].r , ztemp.i = zx[i__2].i;

        if (ztemp.r != 0.0 || ztemp.i != 0.0) {
            i__3 = i__;
            zx[i__2].r = zy[i__3].r , zx[i__2].i = zy[i__3].i;
            zy[i__2].r = ztemp.r , zy[i__2].i = ztemp.i;
        }
    }
}
