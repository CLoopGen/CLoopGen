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
extern real *c__;
extern real *s;
extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
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
for (j = 2; j <= i__1; j += 2) {
    if (j + 1 > i__1) continue;
    real ctemp1 = c__[j - 1], stemp1 = s[j - 1];
    real ctemp2 = c__[j], stemp2 = s[j];
    int cond1 = (ctemp1 != 1.F || stemp1 != 0.F);
    int cond2 = (ctemp2 != 1.F || stemp2 != 0.F);
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        if (cond1) {
            i__3 = i__ + j * a_dim1;
            temp.r = a[i__3].r; temp.i = a[i__3].i;
            q__2.r = ctemp1 * temp.r; q__2.i = ctemp1 * temp.i;
            i__4 = i__ + a_dim1;
            q__3.r = stemp1 * a[i__4].r; q__3.i = stemp1 * a[i__4].i;
            q__1.r = q__2.r - q__3.r; q__1.i = q__2.i - q__3.i;
            a[i__3].r = q__1.r; a[i__3].i = q__1.i;
            q__2.r = stemp1 * temp.r; q__2.i = stemp1 * temp.i;
            q__3.r = ctemp1 * a[i__4].r; q__3.i = ctemp1 * a[i__4].i;
            q__1.r = q__2.r + q__3.r; q__1.i = q__2.i + q__3.i;
            a[i__4].r = q__1.r; a[i__4].i = q__1.i;
        }
        if (cond2) {
            i__3 = i__ + (j + 1) * a_dim1;
            temp.r = a[i__3].r; temp.i = a[i__3].i;
            q__2.r = ctemp2 * temp.r; q__2.i = ctemp2 * temp.i;
            i__4 = i__ + a_dim1;
            q__3.r = stemp2 * a[i__4].r; q__3.i = stemp2 * a[i__4].i;
            q__1.r = q__2.r - q__3.r; q__1.i = q__2.i - q__3.i;
            a[i__3].r = q__1.r; a[i__3].i = q__1.i;
            q__2.r = stemp2 * temp.r; q__2.i = stemp2 * temp.i;
            q__3.r = ctemp2 * a[i__4].r; q__3.i = ctemp2 * a[i__4].i;
            q__1.r = q__2.r + q__3.r; q__1.i = q__2.i + q__3.i;
            a[i__4].r = q__1.r; a[i__4].i = q__1.i;
        }
    }
}
}
