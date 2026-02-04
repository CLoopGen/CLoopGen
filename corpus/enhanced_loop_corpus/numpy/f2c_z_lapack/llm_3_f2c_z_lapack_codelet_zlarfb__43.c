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
for (i__ = 1; i__ <= lastc; ++i__) {
    for (j = 1; j <= i__1; ++j) {
        integer c_offset = (lastv - *k + j) * c_dim1;
        integer work_offset = j * work_dim1;
        integer c_idx = i__ + c_offset;
        integer w_idx = i__ + work_offset;
        doublecomplex temp;
        temp.r = c__[c_idx].r - work[w_idx].r;
        temp.i = c__[c_idx].i - work[w_idx].i;
        c__[c_idx].r = temp.r;
        c__[c_idx].i = temp.i;
    }
}
}
