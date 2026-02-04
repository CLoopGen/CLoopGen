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

typedef int logical;

extern doublecomplex *a;
extern doublecomplex *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;
extern integer j;
extern doublecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
doublecomplex temp_local;
for (j = 1; j <= i__1; ++j) {
    i__2 = j;
    temp_local.r = 0.0; temp_local.i = 0.0;
    if (x[i__2].r != 0. || x[i__2].i != 0.) {
        i__2 = j;
        temp_local.r = x[i__2].r; temp_local.i = x[i__2].i;
        i__2 = j - 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__;
            i__5 = i__ + j * a_dim1;
            z__2.r = temp_local.r * a[i__5].r - temp_local.i * a[i__5].i;
            z__2.i = temp_local.r * a[i__5].i + temp_local.i * a[i__5].r;
            x[i__3].r += z__2.r;
            x[i__3].i += z__2.i;
        }
        if (nounit) {
            i__4 = j + j * a_dim1;
            z__1.r = temp_local.r * a[i__4].r - temp_local.i * a[i__4].i;
            z__1.i = temp_local.r * a[i__4].i + temp_local.i * a[i__4].r;
            x[j].r = z__1.r;
            x[j].i = z__1.i;
        } else {
            x[j].r = temp_local.r;
            x[j].i = temp_local.i;
        }
    }
}
}
