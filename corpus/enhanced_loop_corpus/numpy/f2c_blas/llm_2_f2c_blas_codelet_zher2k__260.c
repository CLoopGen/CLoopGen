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
    ptrdiff_t idx = j + j * c_dim1;
    i__2 = *beta * c__[idx].r;
    c__[idx].r = i__2;
    c__[idx].i = 0.0;
    for (i__ = j + 1; i__ <= *n; ++i__) {
        ptrdiff_t c_idx = i__ + j * c_dim1;
        doublereal br = *beta * c__[c_idx].r;
        doublereal bi = *beta * c__[c_idx].i;
        c__[c_idx].r = br;
        c__[c_idx].i = bi;
    }
}
}
