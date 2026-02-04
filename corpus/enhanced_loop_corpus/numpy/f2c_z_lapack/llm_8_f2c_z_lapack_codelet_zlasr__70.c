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
extern integer i__4;
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
for (j = 1; j <= i__1; ++j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1. || stemp != 0.) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__ + j * a_dim1;
            i__4 = i__ + *n * a_dim1;
            temp.r = a[i__3].r , temp.i = a[i__3].i;
            z__1.r = ctemp * temp.r - stemp * a[i__4].i , z__1.i = ctemp * temp.i + stemp * a[i__4].r;
            z__2.r = stemp * temp.i + ctemp * a[i__4].r , z__2.i = ctemp * a[i__4].i - stemp * temp.r;
            a[i__3].r = z__1.r , a[i__3].i = z__1.i;
            a[i__4].r = z__2.r , a[i__4].i = z__2.i;
        }
    }
}
}
