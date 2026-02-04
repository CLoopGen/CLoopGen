#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *c__;
extern doublereal *s;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern doublereal temp;
extern doublereal ctemp;
extern doublereal stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j <= i__1; ++j) {
    ctemp = c__[j - 1];
    stemp = s[j - 1];
    if (ctemp != 1. || stemp != 0.) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            integer idx_j = i__ + j * a_dim1;
            integer idx_1 = i__ + a_dim1;
            temp = a[idx_j];
            a[idx_j] = ctemp * temp - stemp * a[idx_1];
            a[idx_1] = stemp * temp + ctemp * a[idx_1];
        }
    }
}
}
