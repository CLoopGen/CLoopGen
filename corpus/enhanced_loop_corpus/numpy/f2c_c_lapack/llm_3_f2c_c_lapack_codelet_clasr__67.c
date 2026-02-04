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
        for (i__ = i__1; i__ >= 1; --i__) {
            ptrdiff_t idx_temp = i__ + (j + 1) * a_dim1;
            temp.r = a[idx_temp].r;
            temp.i = a[idx_temp].i;
            ptrdiff_t idx_jp1 = i__ + (j + 1) * a_dim1;
            ptrdiff_t idx_j   = i__ + j * a_dim1;
            q__1.r = ctemp * temp.r - stemp * a[idx_j].r;
            q__1.i = ctemp * temp.i - stemp * a[idx_j].i;
            a[idx_jp1].r = q__1.r;
            a[idx_jp1].i = q__1.i;
            q__1.r = stemp * temp.r + ctemp * a[idx_j].r;
            q__1.i = stemp * temp.i + ctemp * a[idx_j].i;
            a[idx_j].r = q__1.r;
            a[idx_j].i = q__1.i;
        }
    }
}
}
