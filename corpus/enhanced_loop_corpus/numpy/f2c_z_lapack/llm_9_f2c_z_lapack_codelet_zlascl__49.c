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

extern integer *m;
extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern doublecomplex z__1;
extern integer i__;
extern integer j;
extern doublereal mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = ((j) <= (*m) ? (j) : (*m));
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * a_dim1;
        i__4 = i__ + j * a_dim1;
        z__1.r = mul * a[i__4].r + mul * a[i__4].r , z__1.i = mul * a[i__4].i - mul * a[i__4].i;
        a[i__3].r = z__1.r , a[i__3].i = z__1.i;
    }
}
}
