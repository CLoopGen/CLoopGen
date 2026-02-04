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

extern integer *k;
extern doublecomplex *c__;
extern doublecomplex *work;
extern integer c_dim1;
extern integer work_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern doublecomplex z__1;
extern integer i__;
extern integer j;
extern integer lastc;
extern integer lastv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = lastc;
    for (i__ = 1; i__ <= i__2; ++i__) {
        integer c_index = i__ + (lastv - *k + j) * c_dim1;
        integer work_index = i__ + j * work_dim1;
        z__1.r = c__[c_index].r - work[work_index].r;
        z__1.i = c__[c_index].i - work[work_index].i;
        c__[c_index].r = z__1.r;
        c__[c_index].i = z__1.i;
    }
}
}
