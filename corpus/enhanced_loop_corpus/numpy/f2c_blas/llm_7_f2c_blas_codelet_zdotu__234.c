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
    doublecomplex temp_sum;
    temp_sum.r = ztemp.r;
    temp_sum.i = ztemp.i;
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = i__;
        i__3 = i__;
        z__2.r = zx[i__2].r * zy[i__3].r - zx[i__2].i * zy[i__3].i;
        z__2.i = zx[i__2].r * zy[i__3].i + zx[i__2].i * zy[i__3].r;
        temp_sum.r += z__2.r;
        temp_sum.i += z__2.i;
    }
    ztemp.r = temp_sum.r;
    ztemp.i = temp_sum.i;
}
