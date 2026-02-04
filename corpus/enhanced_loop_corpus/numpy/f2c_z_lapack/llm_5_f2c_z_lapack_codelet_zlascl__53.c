#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern doublecomplex z__1;
extern integer i__;
extern integer j;
extern integer k1;
extern integer k2;
extern integer k3;
extern integer k4;
extern doublereal mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__3 = k1 - j;
    i__4 = k3;
    i__5 = k4 - j;
    i__2 = i__5;
    if (i__4 < i__2) {
        i__2 = i__4;
    }
    i__3 = (i__3 > k2) ? i__3 : k2;
    for (i__ = i__3; i__ <= i__2; ++i__) {
        i__4 = i__ + j * a_dim1;
        z__1.r = mul * a[i__4].r;
        z__1.i = mul * a[i__4].i;
        i__3 = i__ + j * a_dim1;
        a[i__3].r = z__1.r;
        a[i__3].i = z__1.i;
    }
}
}
