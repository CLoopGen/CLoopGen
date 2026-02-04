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
    if (j < 2) break;
    ctemp = c__[j];
    stemp = s[j];
    real ctemp_prev = c__[j-1];
    real stemp_prev = s[j-1];
    if ((ctemp != 1.F || stemp != 0.F) || (ctemp_prev != 1.F || stemp_prev != 0.F)) {
        i__1 = *n;
        for (i__ = 1; i__ <= i__1; ++i__) {
            i__2 = j + 1 + i__ * a_dim1;
            temp.r = a[i__2].r; temp.i = a[i__2].i;
            i__3 = j + i__ * a_dim1;
            singlecomplex temp2;
            temp2.r = a[i__3].r; temp2.i = a[i__3].i;

            q__1.r = ctemp * temp.r - stemp * temp2.r;
            q__1.i = ctemp * temp.i - stemp * temp2.i;
            a[i__2].r = q__1.r; a[i__2].i = q__1.i;

            q__1.r = stemp * temp.r + ctemp * temp2.r;
            q__1.i = stemp * temp.i + ctemp * temp2.i;
            a[i__3].r = q__1.r; a[i__3].i = q__1.i;

            i__2 = j + i__ * a_dim1;
            temp.r = a[i__2].r; temp.i = a[i__2].i;
            i__3 = j - 1 + i__ * a_dim1;
            temp2.r = a[i__3].r; temp2.i = a[i__3].i;

            q__1.r = ctemp_prev * temp.r - stemp_prev * temp2.r;
            q__1.i = ctemp_prev * temp.i - stemp_prev * temp2.i;
            a[i__2].r = q__1.r; a[i__2].i = q__1.i;

            q__1.r = stemp_prev * temp.r + ctemp_prev * temp2.r;
            q__1.i = stemp_prev * temp.i + ctemp_prev * temp2.i;
            a[i__3].r = q__1.r; a[i__3].i = q__1.i;
        }
    }
}
}
