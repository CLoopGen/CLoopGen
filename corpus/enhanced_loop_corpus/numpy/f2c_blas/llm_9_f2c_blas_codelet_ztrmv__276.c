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
for (j = *n; j >= 1; j -= 2) {
    if (j < 2) break;
    i__1 = j;
    i__2 = j - 1;
    logical cond1 = (x[i__1].r != 0. || x[i__1].i != 0.);
    logical cond2 = (x[i__2].r != 0. || x[i__2].i != 0.);
    
    if (cond1) {
        temp.r = x[i__1].r; temp.i = x[i__1].i;
        for (i__ = *n; i__ >= j + 1; --i__) {
            i__2 = i__;
            i__4 = i__ + j * a_dim1;
            z__2.r = temp.r * a[i__4].r - temp.i * a[i__4].i;
            z__2.i = temp.r * a[i__4].i + temp.i * a[i__4].r;
            x[i__2].r += z__2.r;
            x[i__2].i += z__2.i;
        }
        if (nounit) {
            i__3 = j + j * a_dim1;
            z__1.r = x[j].r * a[i__3].r - x[j].i * a[i__3].i;
            z__1.i = x[j].r * a[i__3].i + x[j].i * a[i__3].r;
            x[j].r = z__1.r; x[j].i = z__1.i;
        }
    }
    if (cond2) {
        temp.r = x[i__2].r; temp.i = x[i__2].i;
        for (i__ = *n; i__ >= j; --i__) {
            i__2 = i__;
            i__4 = i__ + (j-1) * a_dim1;
            z__2.r = temp.r * a[i__4].r - temp.i * a[i__4].i;
            z__2.i = temp.r * a[i__4].i + temp.i * a[i__4].r;
            x[i__2].r += z__2.r;
            x[i__2].i += z__2.i;
        }
        if (nounit) {
            i__3 = (j-1) + (j-1) * a_dim1;
            z__1.r = x[j-1].r * a[i__3].r - x[j-1].i * a[i__3].i;
            z__1.i = x[j-1].r * a[i__3].i + x[j-1].i * a[i__3].r;
            x[j-1].r = z__1.r; x[j-1].i = z__1.i;
        }
    }
}
}
