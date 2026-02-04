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
if (i__1 >= 1 && lastc >= 1) {
    for (j = 1; j <= i__1; ++j) {
        integer base_j_c = (lastv - *k + j) * c_dim1;
        integer base_j_w = j * work_dim1;
        for (i__ = 1; i__ <= lastc; ++i__) {
            integer offset_i = i__;
            integer idx_c = offset_i + base_j_c;
            integer idx_w = offset_i + base_j_w;
            c__[idx_c].r = c__[idx_c].r - work[idx_w].r;
            c__[idx_c].i = c__[idx_c].i - work[idx_w].i;
        }
    }
}
}
