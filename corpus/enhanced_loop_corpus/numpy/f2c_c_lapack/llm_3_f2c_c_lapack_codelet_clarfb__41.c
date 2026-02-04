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

extern integer *k;
extern singlecomplex *c__;
extern singlecomplex *work;
extern integer c_dim1;
extern integer work_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern singlecomplex q__1;
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
        singlecomplex diff;
        diff.r = c__[i__ + c_offset].r - work[i__ + work_offset].r;
        diff.i = c__[i__ + c_offset].i - work[i__ + work_offset].i;
        c__[i__ + c_offset].r = diff.r;
        c__[i__ + c_offset].i = diff.i;
    }
}
}
