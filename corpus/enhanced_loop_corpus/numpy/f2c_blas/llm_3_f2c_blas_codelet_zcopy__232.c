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
for (i__ = 1; i__ <= i__1; i__ += 2) { // Strided access: step by 2
    i__2 = i__;
    i__3 = i__;
    if (i__ <= i__1) {
        zy[i__2].r = zx[i__3].r;
        zy[i__2].i = zx[i__3].i;
    }
    i__2 = i__ + 1;
    i__3 = i__ + 1;
    if (i__ + 1 <= i__1) {
        zy[i__2].r = zx[i__3].r;
        zy[i__2].i = zx[i__3].i;
    }
}
}
