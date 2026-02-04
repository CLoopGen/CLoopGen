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
        i__3 = i__ + (lastv - *k + j) * c_dim1;
        i__4 = i__ + (lastv - *k + j) * c_dim1;
        i__5 = i__ + j * work_dim1;
        z__1.r = c__[i__4].r - work[i__5].r , z__1.i = c__[i__4].i - work[i__5].i;
        c__[i__3].r = z__1.r , c__[i__3].i = z__1.i;
    }
}

}
