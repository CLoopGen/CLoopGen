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
extern doublecomplex z__1;
extern integer i__;
extern integer j;
extern integer k1;
extern integer k3;
extern doublereal mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = k1 - j;
    i__3 = k3;
    for (i__ = ((i__2) >= (1) ? (i__2) : (1)); i__ <= i__3; i__ += 2) {
        i__4 = i__ + j * a_dim1;
        i__2 = i__ + j * a_dim1;
        z__1.r = mul * a[i__4].r , z__1.i = mul * a[i__4].i;
        a[i__2].r = z__1.r , a[i__2].i = z__1.i;
        if (i__ + 1 <= i__3) {
            i__4 = (i__ + 1) + j * a_dim1;
            i__2 = (i__ + 1) + j * a_dim1;
            z__1.r = mul * a[i__4].r , z__1.i = mul * a[i__4].i;
            a[i__2].r = z__1.r , a[i__2].i = z__1.i;
        }
    }
}
}
