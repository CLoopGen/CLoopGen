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
for (j = 1; j <= i__1 && j <= *n; j += 2) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1. || stemp != 0.) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__ + j * a_dim1;
            temp.r = a[i__3].r; temp.i = a[i__3].i;
            i__4 = i__ + *n * a_dim1;
            z__2.r = stemp * a[i__4].r; z__2.i = stemp * a[i__4].i;
            z__3.r = ctemp * temp.r; z__3.i = ctemp * temp.i;
            z__1.r = z__2.r + z__3.r; z__1.i = z__2.i + z__3.i;
            a[i__3].r = z__1.r; a[i__3].i = z__1.i;
            z__2.r = ctemp * a[i__4].r; z__2.i = ctemp * a[i__4].i;
            z__3.r = stemp * temp.r; z__3.i = stemp * temp.i;
            z__1.r = z__2.r - z__3.r; z__1.i = z__2.i - z__3.i;
            a[i__4].r = z__1.r; a[i__4].i = z__1.i;

            if (j + 1 <= i__1) {
                integer j2 = j + 1;
                doublereal ctemp2 = c__[j2], stemp2 = s[j2];
                i__3 = i__ + j2 * a_dim1;
                doublecomplex temp2;
                temp2.r = a[i__3].r; temp2.i = a[i__3].i;
                i__4 = i__ + *n * a_dim1;
                z__2.r = stemp2 * a[i__4].r; z__2.i = stemp2 * a[i__4].i;
                z__3.r = ctemp2 * temp2.r; z__3.i = ctemp2 * temp2.i;
                z__1.r = z__2.r + z__3.r; z__1.i = z__2.i + z__3.i;
                a[i__3].r = z__1.r; a[i__3].i = z__1.i;
                z__2.r = ctemp2 * a[i__4].r; z__2.i = ctemp2 * a[i__4].i;
                z__3.r = stemp2 * temp2.r; z__3.i = stemp2 * temp2.i;
                z__1.r = z__2.r - z__3.r; z__1.i = z__2.i - z__3.i;
                a[i__4].r = z__1.r; a[i__4].i = z__1.i;
            }
        }
    }
}
}
