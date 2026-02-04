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
    if (ctemp != 1.F || stemp != 0.F) {
        i__1 = *n;
        for (i__ = 1; i__ <= i__1; ++i__) {
            i__2 = j + i__ * a_dim1;
            i__3 = *m + i__ * a_dim1;
            temp.r = a[i__2].r; temp.i = a[i__2].i;
            singlecomplex t1, t2;
            t1.r = ctemp * temp.r - stemp * a[i__3].i;
            t1.i = ctemp * temp.i + stemp * a[i__3].r;
            t2.r = stemp * temp.r + ctemp * a[i__3].r;
            t2.i = stemp * temp.i + ctemp * a[i__3].i;
            a[i__2].r = t1.r; a[i__2].i = t1.i;
            a[i__3].r = t2.r; a[i__3].i = t2.i;
        }
    }
}
}
