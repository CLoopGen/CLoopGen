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
for (j = *n - 1; j >= 1; j -= 2) {
    if (j < 1) break;
    ctemp = c__[j];
    stemp = s[j];
    doublereal ctemp_prev = c__[j-1];
    doublereal stemp_prev = s[j-1];
    integer cond1 = (ctemp != 1. || stemp != 0.);
    integer cond2 = (j > 1 && (ctemp_prev != 1. || stemp_prev != 0.));
    if (cond1 || cond2) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            if (cond1) {
                i__2 = i__ + (j + 1) * a_dim1;
                temp.r = a[i__2].r , temp.i = a[i__2].i;
                z__2.r = ctemp * temp.r , z__2.i = ctemp * temp.i;
                i__3 = i__ + j * a_dim1;
                z__3.r = stemp * a[i__3].r , z__3.i = stemp * a[i__3].i;
                z__1.r = z__2.r - z__3.r , z__1.i = z__2.i - z__3.i;
                a[i__2].r = z__1.r , a[i__2].i = z__1.i;
                z__2.r = stemp * temp.r , z__2.i = stemp * temp.i;
                z__3.r = ctemp * a[i__3].r , z__3.i = ctemp * a[i__3].i;
                z__1.r = z__2.r + z__3.r , z__1.i = z__2.i + z__3.i;
                a[i__3].r = z__1.r , a[i__3].i = z__1.i;
            }
            if (cond2) {
                i__2 = i__ + j * a_dim1;
                temp.r = a[i__2].r , temp.i = a[i__2].i;
                z__2.r = ctemp_prev * temp.r , z__2.i = ctemp_prev * temp.i;
                i__3 = i__ + (j - 1) * a_dim1;
                z__3.r = stemp_prev * a[i__3].r , z__3.i = stemp_prev * a[i__3].i;
                z__1.r = z__2.r - z__3.r , z__1.i = z__2.i - z__3.i;
                a[i__2].r = z__1.r , a[i__2].i = z__1.i;
                z__2.r = stemp_prev * temp.r , z__2.i = stemp_prev * temp.i;
                z__3.r = ctemp_prev * a[i__3].r , z__3.i = ctemp_prev * a[i__3].i;
                z__1.r = z__2.r + z__3.r , z__1.i = z__2.i + z__3.i;
                a[i__3].r = z__1.r , a[i__3].i = z__1.i;
            }
        }
    }
}
}
