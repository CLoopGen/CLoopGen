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
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern integer i__;
extern integer j;
extern real mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__3 = j + 1;
    i__2 = ((i__3) <= (*m) ? (i__3) : (*m));
    for (i__ = i__2; i__ >= 1; --i__) {
        i__3 = i__ + j * a_dim1;
        i__4 = i__ + j * a_dim1;
        q__1.r = mul * a[i__4].r;
        q__1.i = mul * a[i__4].i;
        a[i__3].r = q__1.r;
        a[i__3].i = q__1.i;
    }
}
}
