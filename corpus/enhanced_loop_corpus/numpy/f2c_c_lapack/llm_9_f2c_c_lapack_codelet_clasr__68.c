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
    if (ctemp == 1.F && stemp == 0.F) continue;
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; i__ += 2) {
        singlecomplex temp1, temp2;
        i__3 = i__ + j * a_dim1;
        temp1.r = a[i__3].r; temp1.i = a[i__3].i;
        i__3 = i__ + a_dim1;
        real ari1 = a[i__3].r, aii1 = a[i__3].i;

        q__1.r = ctemp * temp1.r - stemp * ari1;
        q__1.i = ctemp * temp1.i - stemp * aii1;
        a[i__ + j * a_dim1].r = q__1.r;
        a[i__ + j * a_dim1].i = q__1.i;

        q__1.r = stemp * temp1.r + ctemp * ari1;
        q__1.i = stemp * temp1.i + ctemp * aii1;
        a[i__ + a_dim1].r = q__1.r;
        a[i__ + a_dim1].i = q__1.i;

        if (i__ + 1 > i__2) continue;

        i__3 = i__ + 1 + j * a_dim1;
        temp2.r = a[i__3].r; temp2.i = a[i__3].i;
        i__3 = i__ + 1 + a_dim1;
        real ari2 = a[i__3].r, aii2 = a[i__3].i;

        q__1.r = ctemp * temp2.r - stemp * ari2;
        q__1.i = ctemp * temp2.i - stemp * aii2;
        a[i__ + 1 + j * a_dim1].r = q__1.r;
        a[i__ + 1 + j * a_dim1].i = q__1.i;

        q__1.r = stemp * temp2.r + ctemp * ari2;
        q__1.i = stemp * temp2.i + ctemp * aii2;
        a[i__ + 1 + a_dim1].r = q__1.r;
        a[i__ + 1 + a_dim1].i = q__1.i;
    }
}
}
