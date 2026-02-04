#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *m;
extern singlecomplex *c__;
extern real *rwork;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__;
extern integer j;
extern integer l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
real accumulator = 0.0F;
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * c_dim1;
        i__4 = l + (j - 1) * *m + i__ - 1;
        accumulator += rwork[i__4]; // Introduce loop-carried dependency (WAW and RAW on accumulator)
        c__[i__3].r = accumulator; // Makes current write depend on prior iterations
        c__[i__3].i = 0.F;
    }
}
}
