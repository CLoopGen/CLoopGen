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
        for (i__ = 1; i__ <= *n; ++i__) {
            integer index_ji = j + i__ * a_dim1;
            integer index_mi = *m + i__ * a_dim1;
            temp.r = a[index_ji].r; 
            temp.i = a[index_ji].i;
            q__1.r = stemp * a[index_mi].r + ctemp * temp.r;
            q__1.i = stemp * a[index_mi].i + ctemp * temp.i;
            a[index_ji].r = q__1.r;
            a[index_ji].i = q__1.i;
            q__1.r = ctemp * a[index_mi].r - stemp * temp.r;
            q__1.i = ctemp * a[index_mi].i - stemp * temp.i;
            a[index_mi].r = q__1.r;
            a[index_mi].i = q__1.i;
        }
    }
}
}
