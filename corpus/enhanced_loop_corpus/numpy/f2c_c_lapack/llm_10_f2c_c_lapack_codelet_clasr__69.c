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
for (j = *n; j >= 3; j -= 2) {
    ctemp = c__[j - 1];
    stemp = s[j - 1];
    real ctemp_prev = c__[j - 2];
    real stemp_prev = s[j - 2];
    if (ctemp != 1.F || stemp != 0.F || ctemp_prev != 1.F || stemp_prev != 0.F) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            i__2 = i__ + j * a_dim1;
            temp.r = a[i__2].r; temp.i = a[i__2].i;
            singlecomplex temp_prev;
            i__3 = i__ + (j-1) * a_dim1;
            temp_prev.r = a[i__3].r; temp_prev.i = a[i__3].i;

            if (ctemp != 1.F || stemp != 0.F) {
                q__2.r = ctemp * temp.r; q__2.i = ctemp * temp.i;
                i__3 = i__ + a_dim1;
                q__3.r = stemp * a[i__3].r; q__3.i = stemp * a[i__3].i;
                q__1.r = q__2.r - q__3.r; q__1.i = q__2.i - q__3.i;
                a[i__2].r = q__1.r; a[i__2].i = q__1.i;

                q__2.r = stemp * temp.r; q__2.i = stemp * temp.i;
                i__3 = i__ + a_dim1;
                q__3.r = ctemp * a[i__3].r; q__3.i = ctemp * a[i__3].i;
                q__1.r = q__2.r + q__3.r; q__1.i = q__2.i + q__3.i;
                a[i__ + a_dim1].r = q__1.r; a[i__ + a_dim1].i = q__1.i;
            }

            if (j > 2 && (ctemp_prev != 1.F || stemp_prev != 0.F)) {
                i__2 = i__ + (j-1) * a_dim1;
                q__2.r = ctemp_prev * temp_prev.r; q__2.i = ctemp_prev * temp_prev.i;
                i__3 = i__ + a_dim1;
                q__3.r = stemp_prev * a[i__3].r; q__3.i = stemp_prev * a[i__3].i;
                q__1.r = q__2.r - q__3.r; q__1.i = q__2.i - q__3.i;
                a[i__2].r = q__1.r; a[i__2].i = q__1.i;

                q__2.r = stemp_prev * temp_prev.r; q__2.i = stemp_prev * temp_prev.i;
                i__3 = i__ + a_dim1;
                q__3.r = ctemp_prev * a[i__3].r; q__3.i = ctemp_prev * a[i__3].i;
                q__1.r = q__2.r + q__3.r; q__1.i = q__2.i + q__3.i;
                a[i__ + a_dim1].r = q__1.r; a[i__ + a_dim1].i = q__1.i;
            }
        }
    }
}
}
