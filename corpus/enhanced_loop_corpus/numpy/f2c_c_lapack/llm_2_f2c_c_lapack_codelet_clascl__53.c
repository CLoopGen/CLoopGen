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

extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern singlecomplex q__1;
extern integer i__;
extern integer j;
extern integer k1;
extern integer k2;
extern integer k3;
extern integer k4;
extern real mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__3 = k1 - j;
    i__4 = k3 , i__5 = k4 - j;
    i__2 = ((i__4) <= (i__5) ? (i__4) : (i__5));
    for (i__ = ((i__3) >= (k2) ? (i__3) : (k2)); i__ <= i__2; ++i__) {
        i__3 = i__ + j * a_dim1;
        i__4 = i__ + j * a_dim1;
        q__1.r = mul * a[i__4].r , q__1.i = mul * a[i__4].i;
        a[i__3].r = q__1.r , a[i__3].i = q__1.i;
    }
}
}
