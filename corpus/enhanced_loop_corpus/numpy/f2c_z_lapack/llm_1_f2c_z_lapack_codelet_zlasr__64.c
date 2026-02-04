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
if (i__1 <= 0 || *n <= 0) return;
for (j = 1; j <= i__1; ++j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp == 1. && stemp == 0.) continue;
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = j + i__ * a_dim1;
        temp = a[i__3];
        i__4 = *m + i__ * a_dim1;
        doublecomplex* col_m = &a[i__4];
        z__1.r = ctemp * temp.r + stemp * col_m->r;
        z__1.i = ctemp * temp.i + stemp * col_m->i;
        a[i__3].r = z__1.r; a[i__3].i = z__1.i;
        z__1.r = ctemp * col_m->r - stemp * temp.r;
        z__1.i = ctemp * col_m->i - stemp * temp.i;
        col_m->r = z__1.r; col_m->i = z__1.i;
    }
}
}
