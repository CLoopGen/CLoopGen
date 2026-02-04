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
for (j = 1; j <= i__1; ++j) {
    i__2 = lastc;
    for (i__ = 1; i__ <= i__2; ++i__) {
        integer c_index = i__ + (lastv - *k + j) * c_dim1;
        integer work_index = i__ + j * work_dim1;
        q__1.r = c__[c_index].r - work[work_index].r;
        q__1.i = c__[c_index].i - work[work_index].i;
        c__[c_index].r = q__1.r;
        c__[c_index].i = q__1.i;
    }
}
}
