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

extern integer *m;
extern singlecomplex *a;
extern singlecomplex *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    real prev_r = 0.0f, prev_i = 0.0f;
    for (i__ = j; i__ <= i__2; ++i__) {
        i__3 = i__ + j * b_dim1;
        i__4 = i__ + j * a_dim1;
        real curr_r = a[i__4].r + prev_r;
        real curr_i = a[i__4].i + prev_i;
        b[i__3].r = curr_r;
        b[i__3].i = curr_i;
        prev_r = curr_r;
        prev_i = curr_i;
    }
}
}
