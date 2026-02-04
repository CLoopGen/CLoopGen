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
for (j = 2; j <= i__1; ++j) {
    ctemp = c__[j - 1];
    stemp = s[j - 1];
    if (ctemp != 1. || stemp != 0.) {
        i__2 = *m;
        doublecomplex *col_j = &a[j * a_dim1 + 1];
        doublecomplex *col_1 = &a[a_dim1 + 1];
        for (i__ = 1; i__ <= i__2; ++i__) {
            temp.r = col_j[i__].r; temp.i = col_j[i__].i;
            z__1.r = ctemp * temp.r - stemp * col_1[i__].r;
            z__1.i = ctemp * temp.i - stemp * col_1[i__].i;
            col_j[i__].r = z__1.r; col_j[i__].i = z__1.i;
            z__1.r = stemp * temp.r + ctemp * col_1[i__].r;
            z__1.i = stemp * temp.i + ctemp * col_1[i__].i;
            col_1[i__].r = z__1.r; col_1[i__].i = z__1.i;
        }
    }
}
}
