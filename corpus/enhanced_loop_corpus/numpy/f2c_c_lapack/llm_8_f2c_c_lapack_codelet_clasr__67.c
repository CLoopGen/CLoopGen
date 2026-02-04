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
for (j = *n - 1; j >= 1; --j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1.F || stemp != 0.F) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            i__2 = i__ + (j + 1) * a_dim1;
            i__3 = i__ + j * a_dim1;
            temp.r = a[i__2].r; temp.i = a[i__2].i;
            singlecomplex a_j_i = a[i__3];
            real a_r = a_j_i.r, a_i_val = a_j_i.i;
            a[i__2].r = ctemp * temp.r - stemp * a_r;
            a[i__2].i = ctemp * temp.i - stemp * a_i_val;
            a[i__3].r = stemp * temp.r + ctemp * a_r;
            a[i__3].i = stemp * temp.i + ctemp * a_i_val;
        }
    }
}
}
