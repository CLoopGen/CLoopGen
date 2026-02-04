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
// Strided access: traverse array with a stride of 2, forward and backward pass
integer stride = 2;
integer n = i__1;

// Forward pass: even indices
for (i__ = 1; i__ <= n; i__ += stride) {
    i__2 = i__;
    ztemp.r = zx[i__2].r; ztemp.i = zx[i__2].i;
    i__3 = i__;
    zx[i__2].r = zy[i__3].r; zx[i__2].i = zy[i__3].i;
    zy[i__2].r = ztemp.r; zy[i__2].i = ztemp.i;
}

// Backward pass: odd indices in reverse order
for (i__ = (n % 2 == 0 ? n - 1 : n); i__ >= 1; i__ -= stride) {
    i__2 = i__;
    ztemp.r = zx[i__2].r; ztemp.i = zx[i__2].i;
    i__3 = i__;
    zx[i__2].r = zy[i__3].r; zx[i__2].i = zy[i__3].i;
    zy[i__2].r = ztemp.r; zy[i__2].i = ztemp.i;
}
}
