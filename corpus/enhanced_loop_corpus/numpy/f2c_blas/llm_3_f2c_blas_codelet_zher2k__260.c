#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

extern integer *n;
extern doublereal *beta;
extern doublecomplex *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern doublereal d__1;
extern doublecomplex z__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    ptrdiff_t diag_offset = j * (c_dim1 + 1);
    d__1 = *beta * c__[diag_offset].r;
    c__[diag_offset].r = d__1;
    c__[diag_offset].i = 0.0;
    ptrdiff_t col_base = j * c_dim1;
    i__2 = *n;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        ptrdiff_t linear_idx = i__ + col_base;
        z__1.r = *beta * c__[linear_idx].r;
        z__1.i = *beta * c__[linear_idx].i;
        c__[linear_idx].r = z__1.r;
        c__[linear_idx].i = z__1.i;
    }
}
}
