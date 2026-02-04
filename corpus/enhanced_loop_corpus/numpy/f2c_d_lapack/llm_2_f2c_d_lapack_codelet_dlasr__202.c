#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern integer *n;
extern doublereal *c__;
extern doublereal *s;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__;
extern integer j;
extern doublereal temp;
extern doublereal ctemp;
extern doublereal stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n - 1; j >= 1; --j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1. || stemp != 0.) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            integer idx_j   = i__ + j * a_dim1;
            integer idx_jp1 = i__ + (j + 1) * a_dim1;
            temp = a[idx_jp1];
            a[idx_jp1] = ctemp * temp - stemp * a[idx_j];
            a[idx_j] = stemp * temp + ctemp * a[idx_j];
        }
    }
}
}
