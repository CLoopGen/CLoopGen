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

typedef int logical;

extern integer *n;
extern singlecomplex *a;
extern singlecomplex *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer j;
extern singlecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n; j >= 1; --j) {
    i__1 = j;
    if (x[i__1].r == 0.F && x[i__1].i == 0.F) continue;
    temp.r = x[j].r; temp.i = x[j].i;
    for (i__ = *n; i__ > j; --i__) {
        i__4 = i__ + j * a_dim1;
        q__2.r = temp.r * a[i__4].r - temp.i * a[i__4].i;
        q__2.i = temp.r * a[i__4].i + temp.i * a[i__4].r;
        x[i__].r += q__2.r;
        x[i__].i += q__2.i;
    }
    if (nounit) {
        i__3 = j + j * a_dim1;
        q__1.r = x[j].r * a[i__3].r - x[j].i * a[i__3].i;
        q__1.i = x[j].r * a[i__3].i + x[j].i * a[i__3].r;
        x[j].r = q__1.r;
        x[j].i = q__1.i;
    }
}
}
