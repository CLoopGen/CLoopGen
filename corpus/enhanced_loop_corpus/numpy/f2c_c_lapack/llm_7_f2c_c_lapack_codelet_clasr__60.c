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

extern integer *n;
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
for (j = 1; j <= i__1; ++j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1.F || stemp != 0.F) {
        i__2 = *n;
        temp.r = 0.0F, temp.i = 0.0F;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = j + 1 + i__ * a_dim1;
            singlecomplex prev;
            prev.r = a[i__3].r, prev.i = a[i__3].i;
            q__2.r = ctemp * prev.r, q__2.i = ctemp * prev.i;
            i__4 = j + i__ * a_dim1;
            q__3.r = stemp * a[i__4].r, q__3.i = stemp * a[i__4].i;
            q__1.r = q__2.r - q__3.r, q__1.i = q__2.i - q__3.i;
            a[i__3].r = q__1.r, a[i__3].i = q__1.i;
            q__2.r = stemp * prev.r, q__2.i = stemp * prev.i;
            q__3.r = ctemp * a[i__4].r, q__3.i = ctemp * a[i__4].i;
            q__1.r = q__2.r + q__3.r, q__1.i = q__2.i + q__3.i;
            temp.r = q__1.r, temp.i = q__1.i;
            a[i__4].r = temp.r, a[i__4].i = temp.i;
        }
    }
}
}
