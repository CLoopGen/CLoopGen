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

typedef int logical;

extern integer *n;
extern doublecomplex *a;
extern doublecomplex *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;
extern integer j;
extern doublecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (*n <= 0) return;
for (j = *n; j >= 1; --j) {
    i__1 = j;
    if (x[i__1].r == 0. && x[i__1].i == 0.) continue;

    temp.r = x[j].r; temp.i = x[j].i;
    i__1 = j + 1;

    integer trip_count = *n - j;
    if (trip_count > 0) {
        for (i__ = *n; i__ >= i__1; --i__) {
            i__4 = i__ + j * a_dim1;
            z__2.r = temp.r * a[i__4].r - temp.i * a[i__4].i;
            z__2.i = temp.r * a[i__4].i + temp.i * a[i__4].r;
            x[i__].r += z__2.r;
            x[i__].i += z__2.i;
        }
    }

    if (nounit) {
        i__3 = j + j * a_dim1;
        doublereal ar = a[i__3].r, ai = a[i__3].i;
        z__1.r = x[j].r * ar - x[j].i * ai;
        z__1.i = x[j].r * ai + x[j].i * ar;
        x[j].r = z__1.r;
        x[j].i = z__1.i;
    }
}
}
