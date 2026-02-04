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
        integer stride = a_dim1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            integer base_i = i__;
            temp = a[base_i + j * stride];
            a[base_i + j * stride] = ctemp * temp - stemp * a[base_i + stride];
            a[base_i + stride] = stemp * temp + ctemp * a[base_i + stride];
        }
    }
}
}
