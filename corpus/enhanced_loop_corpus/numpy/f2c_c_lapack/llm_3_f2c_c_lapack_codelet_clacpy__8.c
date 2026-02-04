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
    i__2 = ((j) <= (*m) ? (j) : (*m));
    integer base_b = j * b_dim1;
    integer base_a = j * a_dim1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        singlecomplex* src = &a[i__ + base_a];
        singlecomplex* dst = &b[i__ + base_b];
        dst->r = src->r;
        dst->i = src->i;
    }
}
}
