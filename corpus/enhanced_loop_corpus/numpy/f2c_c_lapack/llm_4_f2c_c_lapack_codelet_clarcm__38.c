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
extern integer i__5;
extern real r__1;
extern singlecomplex q__1;
extern integer i__;
extern integer j;
extern integer l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= *m; ++i__) {
    for (j = 1; j <= i__1; ++j) {
        i__3 = i__ + j * c_dim1;
        i__5 = l + (j - 1) * *m + i__ - 1;
        q__1.r = c__[i__3].r;
        q__1.i = rwork[i__5];
        c__[i__3].r = q__1.r;
        c__[i__3].i = q__1.i;
    }
}
}
