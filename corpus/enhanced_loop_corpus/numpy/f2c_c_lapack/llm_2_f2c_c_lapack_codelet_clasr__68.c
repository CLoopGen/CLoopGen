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
for (j = 2; j <= i__1; ++j) {
    ctemp = c__[j - 1];
    stemp = s[j - 1];
    if (ctemp != 1.F || stemp != 0.F) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            integer idx_j = i__ + j * a_dim1;
            integer idx_1 = i__ + a_dim1;
            temp.r = a[idx_j].r; temp.i = a[idx_j].i;
            q__1.r = ctemp * temp.r - stemp * a[idx_1].r;
            q__1.i = ctemp * temp.i - stemp * a[idx_1].i;
            a[idx_j].r = q__1.r; a[idx_j].i = q__1.i;
            q__1.r = stemp * temp.r + ctemp * a[idx_1].r;
            q__1.i = stemp * temp.i + ctemp * a[idx_1].i;
            a[idx_1].r = q__1.r; a[idx_1].i = q__1.i;
        }
    }
}
}
