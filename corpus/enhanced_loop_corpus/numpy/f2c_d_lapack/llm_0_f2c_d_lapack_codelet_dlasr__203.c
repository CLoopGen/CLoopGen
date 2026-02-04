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
        for (i__ = 1; i__ <= *m; ++i__) {
            temp = a[i__ + j * a_dim1];
            a[i__ + j * a_dim1] = ctemp * temp - stemp * a[i__ + a_dim1];
            a[i__ + a_dim1] = stemp * temp + ctemp * a[i__ + a_dim1];
        }
    }
}
}
