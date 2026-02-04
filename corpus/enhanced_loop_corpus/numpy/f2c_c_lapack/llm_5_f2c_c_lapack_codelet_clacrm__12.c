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
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    if (j > (*m / 2)) {
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__ + j * c_dim1;
            i__4 = l + (j - 1) * *m + i__ - 1;
            c__[i__3].r = rwork[i__4] * 2.0F;
            c__[i__3].i = 0.F;
        }
    } else {
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__ + j * c_dim1;
            i__4 = l + (j - 1) * *m + i__ - 1;
            c__[i__3].r = rwork[i__4];
            c__[i__3].i = 0.F;
        }
    }
}
}
