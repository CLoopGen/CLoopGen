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
for (j = *m - 1; j >= 1; --j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1. || stemp != 0.) {
        i__1 = *n;
        for (i__ = 1; i__ <= i__1; ++i__) {
            i__2 = j + i__ * a_dim1;
            i__3 = *m + i__ * a_dim1;
            temp.r = a[i__2].r , temp.i = a[i__2].i;
            doublereal aj_r = a[i__2].r, aj_i = a[i__2].i;
            doublereal am_r = a[i__3].r, am_i = a[i__3].i;
            a[i__2].r = ctemp * aj_r + stemp * am_r;
            a[i__2].i = ctemp * aj_i + stemp * am_i;
            a[i__3].r = ctemp * am_r - stemp * aj_r;
            a[i__3].i = ctemp * am_i - stemp * aj_i;
        }
    }
}
}
