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
    doublecomplex temp;
    for (i__ = 1; i__ <= i__1; ++i__) {
        // Introduce local dependency: read zx[i], write to temp, then use temp to update zy[i]
        // This creates a WAW and RAW dependency within the iteration but eliminates loop-carried dependencies
        // by using a local temporary variable and ensuring no cross-iteration data flow.
        i__2 = i__;
        temp.r = zx[i__2].r;
        temp.i = zx[i__2].i;
        i__2 = i__;
        zx[i__2].r = zy[i__2].r;
        zx[i__2].i = zy[i__2].i;
        i__2 = i__;
        zy[i__2].r = temp.r;
        zy[i__2].i = temp.i;
    }
}
