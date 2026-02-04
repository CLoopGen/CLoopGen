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
for (j = *n - 1; j >= 1; j -= 2) {
    if (j < 2) break;
    ctemp = c__[j];
    stemp = s[j];
    real ctemp_prev = c__[j-1];
    real stemp_prev = s[j-1];
    if (ctemp != 1.F || stemp != 0.F || ctemp_prev != 1.F || stemp_prev != 0.F) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            i__2 = i__ + j * a_dim1;
            temp.r = a[i__2].r , temp.i = a[i__2].i;
            i__3 = i__ + *n * a_dim1;
            singlecomplex temp_n;
            temp_n.r = a[i__3].r , temp_n.i = a[i__3].i;

            q__2.r = stemp * temp_n.r , q__2.i = stemp * temp_n.i;
            q__3.r = ctemp * temp.r , q__3.i = ctemp * temp.i;
            q__1.r = q__2.r + q__3.r , q__1.i = q__2.i + q__3.i;
            a[i__2].r = q__1.r , a[i__2].i = q__1.i;

            q__2.r = ctemp * temp_n.r , q__2.i = ctemp * temp_n.i;
            q__3.r = stemp * temp.r , q__3.i = stemp * temp.i;
            q__1.r = q__2.r - q__3.r , q__1.i = q__2.i - q__3.i;
            a[i__3].r = q__1.r , a[i__3].i = q__1.i;

            i__2 = i__ + (j-1) * a_dim1;
            singlecomplex temp_prev;
            temp_prev.r = a[i__2].r , temp_prev.i = a[i__2].i;

            q__2.r = stemp_prev * temp_n.r , q__2.i = stemp_prev * temp_n.i;
            q__3.r = ctemp_prev * temp_prev.r , q__3.i = ctemp_prev * temp_prev.i;
            q__1.r = q__2.r + q__3.r , q__1.i = q__2.i + q__3.i;
            a[i__2].r = q__1.r , a[i__2].i = q__1.i;

            q__2.r = ctemp_prev * temp_n.r , q__2.i = ctemp_prev * temp_n.i;
            q__3.r = stemp_prev * temp_prev.r , q__3.i = stemp_prev * temp_prev.i;
            q__1.r = q__2.r - q__3.r , q__1.i = q__2.i - q__3.i;
            a[i__3].r = q__1.r , a[i__3].i = q__1.i;
        }
    }
}
}
