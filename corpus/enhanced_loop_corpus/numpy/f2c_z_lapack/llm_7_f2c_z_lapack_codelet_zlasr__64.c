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
        i__2 = *n;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = j + i__ * a_dim1;
            i__4 = *m + i__ * a_dim1;
            temp.r = a[i__3].r; temp.i = a[i__3].i;
            doublecomplex t1, t2, t3;
            t1.r = stemp * a[i__4].r; t1.i = stemp * a[i__4].i;
            t2.r = ctemp * temp.r; t2.i = ctemp * temp.i;
            t3.r = t1.r + t2.r; t3.i = t1.i + t2.i;
            a[i__3].r = t3.r; a[i__3].i = t3.i;
            t1.r = ctemp * a[i__4].r; t1.i = ctemp * a[i__4].i;
            t2.r = stemp * temp.r; t2.i = stemp * temp.i;
            t3.r = t1.r - t2.r; t3.i = t1.i - t2.i;
            a[i__4].r = t3.r; a[i__4].i = t3.i;
        }
    }
}
}
