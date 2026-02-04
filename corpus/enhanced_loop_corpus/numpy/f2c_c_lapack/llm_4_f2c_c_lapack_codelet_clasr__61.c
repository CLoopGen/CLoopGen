#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *m;
extern integer *n;
extern real *c__;
extern real *s;
extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern singlecomplex q__3;
extern integer i__;
extern integer j;
extern singlecomplex temp;
extern real ctemp;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *m - 1; j >= 1; --j) {
    ctemp = c__[j];
    stemp = s[j];
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
        if (ctemp == 1.F && stemp == 0.F) continue;
        i__2 = j + 1 + i__ * a_dim1;
        temp.r = a[i__2].r , temp.i = a[i__2].i;
        i__2 = j + 1 + i__ * a_dim1;
        q__2.r = ctemp * temp.r , q__2.i = ctemp * temp.i;
        i__3 = j + i__ * a_dim1;
        q__3.r = stemp * a[i__3].r , q__3.i = stemp * a[i__3].i;
        q__1.r = q__2.r - q__3.r , q__1.i = q__2.i - q__3.i;
        a[i__2].r = q__1.r , a[i__2].i = q__1.i;
        i__2 = j + i__ * a_dim1;
        q__2.r = stemp * temp.r , q__2.i = stemp * temp.i;
        i__3 = j + i__ * a_dim1;
        q__3.r = ctemp * a[i__3].r , q__3.i = ctemp * a[i__3].i;
        q__1.r = q__2.r + q__3.r , q__1.i = q__2.i + q__3.i;
        a[i__2].r = q__1.r , a[i__2].i = q__1.i;
    }
}
}
