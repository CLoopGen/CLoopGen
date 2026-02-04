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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; i__ += 2) {  // Increase trip count control: step by 2
    i__2 = i__;
    i__3 = i__;
    // First element copy
    zy[i__2].r = zx[i__3].r;
    zy[i__2].i = zx[i__3].i;
    // Second element copy (unrolled once)
    if (i__ + 1 <= i__1) {
        i__2 = i__ + 1;
        i__3 = i__ + 1;
        zy[i__2].r = zx[i__3].r;
        zy[i__2].i = zx[i__3].i;
    }
}
}
