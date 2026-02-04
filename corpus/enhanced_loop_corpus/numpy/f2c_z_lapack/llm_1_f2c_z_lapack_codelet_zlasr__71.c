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
for (j = *n - 1; j >= 1; --j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1. || stemp != 0.) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            for (int k = 0; k < 1; ++k) {
                i__2 = i__ + j * a_dim1;
                temp.r = a[i__2].r , temp.i = a[i__2].i;
                i__3 = i__ + *n * a_dim1;
                z__2.r = stemp * a[i__3].r ; z__2.i = stemp * a[i__3].i;
                z__3.r = ctemp * temp.r ; z__3.i = ctemp * temp.i;
                z__1.r = z__2.r + z__3.r ; z__1.i = z__2.i + z__3.i;
                a[i__2].r = z__1.r ; a[i__2].i = z__1.i;
                z__2.r = ctemp * a[i__3].r ; z__2.i = ctemp * a[i__3].i;
                z__3.r = stemp * temp.r ; z__3.i = stemp * temp.i;
                z__1.r = z__2.r - z__3.r ; z__1.i = z__2.i - z__3.i;
                a[i__3].r = z__1.r ; a[i__3].i = z__1.i;
            }
        }
    }
}
}
