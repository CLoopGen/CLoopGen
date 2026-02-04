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
        i__3 = i__ + (lastv - *k + j) * c_dim1;
        i__4 = i__ + (lastv - *k + j) * c_dim1;
        i__5 = i__ + j * work_dim1;
        q__1.r = c__[i__4].r - work[i__5].r , q__1.i = c__[i__4].i - work[i__5].i;
        c__[i__3].r = q__1.r , c__[i__3].i = q__1.i;
    }
}

}
