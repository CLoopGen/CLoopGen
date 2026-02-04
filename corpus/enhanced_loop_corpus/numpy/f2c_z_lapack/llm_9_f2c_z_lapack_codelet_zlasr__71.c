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
extern integer *n;
extern doublereal *c__;
extern doublereal *s;
extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern doublecomplex z__3;
extern integer i__;
extern integer j;
extern doublecomplex temp;
extern doublereal ctemp;
extern doublereal stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n - 1; j >= 2; j -= 2) {
    integer j1 = j;
    integer j2 = j - 1;
    doublereal ctemp1 = c__[j1];
    doublereal stemp1 = s[j1];
    doublereal ctemp2 = c__[j2];
    doublereal stemp2 = s[j2];
    if (ctemp1 != 1. || stemp1 != 0. || ctemp2 != 1. || stemp2 != 0.) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            i__2 = i__ + j1 * a_dim1;
            temp.r = a[i__2].r; temp.i = a[i__2].i;
            i__3 = i__ + *n * a_dim1;
            z__2.r = stemp1 * a[i__3].r; z__2.i = stemp1 * a[i__3].i;
            z__3.r = ctemp1 * temp.r; z__3.i = ctemp1 * temp.i;
            z__1.r = z__2.r + z__3.r; z__1.i = z__2.i + z__3.i;
            a[i__2].r = z__1.r; a[i__2].i = z__1.i;
            z__2.r = ctemp1 * a[i__3].r; z__2.i = ctemp1 * a[i__3].i;
            z__3.r = stemp1 * temp.r; z__3.i = stemp1 * temp.i;
            z__1.r = z__2.r - z__3.r; z__1.i = z__2.i - z__3.i;
            a[i__3].r = z__1.r; a[i__3].i = z__1.i;

            i__2 = i__ + j2 * a_dim1;
            temp.r = a[i__2].r; temp.i = a[i__2].i;
            z__2.r = stemp2 * a[i__3].r; z__2.i = stemp2 * a[i__3].i;
            z__3.r = ctemp2 * temp.r; z__3.i = ctemp2 * temp.i;
            z__1.r = z__2.r + z__3.r; z__1.i = z__2.i + z__3.i;
            a[i__2].r = z__1.r; a[i__2].i = z__1.i;
            z__2.r = ctemp2 * a[i__3].r; z__2.i = ctemp2 * a[i__3].i;
            z__3.r = stemp2 * temp.r; z__3.i = stemp2 * temp.i;
            z__1.r = z__2.r - z__3.r; z__1.i = z__2.i - z__3.i;
            a[i__3].r = z__1.r; a[i__3].i = z__1.i;
        }
    }
}
}
