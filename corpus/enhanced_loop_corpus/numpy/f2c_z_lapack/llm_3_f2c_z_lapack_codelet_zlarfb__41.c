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
    integer base_c = (lastv - *k + j) * c_dim1;
    integer base_work = j * work_dim1;
    for (i__ = 1; i__ <= lastc; ++i__) {
        integer c_offset = i__ + base_c;
        integer work_offset = i__ + base_work;
        c__[c_offset].r = c__[c_offset].r - work[work_offset].r;
        c__[c_offset].i = c__[c_offset].i - work[work_offset].i;
    }
}
}
