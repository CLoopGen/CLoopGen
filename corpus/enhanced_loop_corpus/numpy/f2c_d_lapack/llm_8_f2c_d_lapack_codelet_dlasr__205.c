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
extern integer i__2;
extern integer i__;
extern integer j;
extern doublereal temp;
extern doublereal ctemp;
extern doublereal stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1. || stemp != 0.) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            temp = a[i__ + j * a_dim1];
            a[i__ + j * a_dim1] = stemp * a[i__ + *n * a_dim1] + ctemp * temp;
            a[i__ + *n * a_dim1] = ctemp * a[i__ + *n * a_dim1] - stemp * temp;
        }
    } else {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            a[i__ + j * a_dim1] *= 1.0;
        }
    }
}
}
