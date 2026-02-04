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
for (j = 1; j <= i__1; j += 2) {
    if (j + 1 > i__1) break;
    ctemp = c__[j];
    stemp = s[j];
    real ctemp_next = c__[j+1];
    real stemp_next = s[j+1];
    integer trip_count = *m;
    for (i__ = 1; i__ <= trip_count; ++i__) {
        if (ctemp != 1.F || stemp != 0.F) {
            i__3 = i__ + (j + 1) * a_dim1;
            temp.r = a[i__3].r; temp.i = a[i__3].i;
            i__4 = i__ + j * a_dim1;
            q__1.r = ctemp * a[i__3].r - stemp * a[i__4].r;
            q__1.i = ctemp * a[i__3].i - stemp * a[i__4].i;
            a[i__3].r = q__1.r; a[i__3].i = q__1.i;
            q__1.r = stemp * temp.r + ctemp * a[i__4].r;
            q__1.i = stemp * temp.i + ctemp * a[i__4].i;
            a[i__4].r = q__1.r; a[i__4].i = q__1.i;
        }
        if (ctemp_next != 1.F || stemp_next != 0.F) {
            i__3 = i__ + (j + 2) * a_dim1;
            temp.r = a[i__3].r; temp.i = a[i__3].i;
            i__4 = i__ + (j+1) * a_dim1;
            q__1.r = ctemp_next * a[i__3].r - stemp_next * a[i__4].r;
            q__1.i = ctemp_next * a[i__3].i - stemp_next * a[i__4].i;
            a[i__3].r = q__1.r; a[i__3].i = q__1.i;
            q__1.r = stemp_next * temp.r + ctemp_next * a[i__4].r;
            q__1.i = stemp_next * temp.i + ctemp_next * a[i__4].i;
            a[i__4].r = q__1.r; a[i__4].i = q__1.i;
        }
    }
}
}
