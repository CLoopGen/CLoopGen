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
if (i__1 >= 1 && lastc >= 1) {
    for (j = 1; j <= i__1; ++j) {
        integer base_j = (lastv - *k + j) * c_dim1;
        integer base_work_j = j * work_dim1;
        for (i__ = 1; i__ <= lastc; ++i__) {
            integer offset_i = i__;
            integer idx_c = offset_i + base_j;
            integer idx_work = offset_i + base_work_j;
            singlecomplex temp;
            temp.r = c__[idx_c].r - work[idx_work].r;
            temp.i = c__[idx_c].i - work[idx_work].i;
            c__[idx_c].r = temp.r;
            c__[idx_c].i = temp.i;
        }
    }
}
}
