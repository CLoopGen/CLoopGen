#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    int base_j_c = j * c_dim1;
    int base_j_work = j * work_dim1;
    for (i__ = 1; i__ <= lastc; ++i__) {
        int idx_c = i__ + base_j_c;
        int idx_work = i__ + base_j_work;
        singlecomplex temp;
        temp.r = c__[idx_c].r - work[idx_work].r;
        temp.i = c__[idx_c].i - work[idx_work].i;
        c__[idx_c] = temp;
    }
}
}
