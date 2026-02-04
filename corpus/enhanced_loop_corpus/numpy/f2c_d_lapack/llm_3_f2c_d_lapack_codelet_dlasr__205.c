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
        integer stride = a_dim1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            integer base_i = i__ - 1;
            integer offset_j = base_i + j * stride;
            integer offset_n = base_i + *n * stride;
            temp = a[offset_j];
            a[offset_j] = stemp * a[offset_n] + ctemp * temp;
            a[offset_n] = ctemp * a[offset_n] - stemp * temp;
        }
    }
}
}
