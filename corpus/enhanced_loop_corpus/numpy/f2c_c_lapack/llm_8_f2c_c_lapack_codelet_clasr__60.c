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
for (j = 1; j <= i__1; j += 2) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1.F || stemp != 0.F) {
        i__2 = *n;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = j + 1 + i__ * a_dim1;
            temp.r = a[i__3].r , temp.i = a[i__3].i;
            i__4 = j + i__ * a_dim1;
            q__1.r = ctemp * a[i__4].r - stemp * a[i__4].i;
            q__1.i = ctemp * a[i__4].i + stemp * a[i__4].r;
            a[i__3].r = ctemp * temp.r - stemp * a[j + i__ * a_dim1].i;
            a[i__3].i = ctemp * temp.i + stemp * a[j + i__ * a_dim1].r;
            a[i__4].r = q__1.r;
            a[i__4].i = q__1.i;
        }
    }
}
}
