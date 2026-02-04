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
for (j = *m - 1; j >= 1; j -= 2) {
    if (j <= 1) break;
    ctemp = c__[j];
    stemp = s[j];
    real ctemp_prev = c__[j-1];
    real stemp_prev = s[j-1];
    int apply_transform_curr = (ctemp != 1.F || stemp != 0.F);
    int apply_transform_prev = (ctemp_prev != 1.F || stemp_prev != 0.F);
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
        if (apply_transform_curr) {
            i__2 = j + i__ * a_dim1;
            temp.r = a[i__2].r , temp.i = a[i__2].i;
            i__3 = *m + i__ * a_dim1;
            q__2.r = stemp * a[i__3].r , q__2.i = stemp * a[i__3].i;
            q__3.r = ctemp * temp.r , q__3.i = ctemp * temp.i;
            q__1.r = q__2.r + q__3.r , q__1.i = q__2.i + q__3.i;
            a[i__2].r = q__1.r , a[i__2].i = q__1.i;
            q__2.r = ctemp * a[i__3].r , q__2.i = ctemp * a[i__3].i;
            q__3.r = stemp * temp.r , q__3.i = stemp * temp.i;
            q__1.r = q__2.r - q__3.r , q__1.i = q__2.i - q__3.i;
            a[i__3].r = q__1.r , a[i__3].i = q__1.i;
        }
        if (apply_transform_prev) {
            i__2 = (j-1) + i__ * a_dim1;
            temp.r = a[i__2].r , temp.i = a[i__2].i;
            i__3 = *m + i__ * a_dim1;
            q__2.r = stemp_prev * a[i__3].r , q__2.i = stemp_prev * a[i__3].i;
            q__3.r = ctemp_prev * temp.r , q__3.i = ctemp_prev * temp.i;
            q__1.r = q__2.r + q__3.r , q__1.i = q__2.i + q__3.i;
            a[i__2].r = q__1.r , a[i__2].i = q__1.i;
            q__2.r = ctemp_prev * a[i__3].r , q__2.i = ctemp_prev * a[i__3].i;
            q__3.r = stemp_prev * temp.r , q__3.i = stemp_prev * temp.i;
            q__1.r = q__2.r - q__3.r , q__1.i = q__2.i - q__3.i;
            a[i__3].r = q__1.r , a[i__3].i = q__1.i;
        }
    }
}
}
