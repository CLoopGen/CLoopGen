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
extern singlecomplex q__1;
extern integer i__;
extern integer j;
extern integer k1;
extern integer k3;
extern real mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = k1 - j;
    for (i__ = ((i__2) >= (1) ? (i__2) : (1)); i__ <= k3; ++i__) {
        i__4 = i__ + j * a_dim1;
        q__1.r = mul * a[i__4].r , q__1.i = mul * a[i__4].i;
        a[i__ + j * a_dim1].r = q__1.r , a[i__ + j * a_dim1].i = q__1.i;
    }
}
}
