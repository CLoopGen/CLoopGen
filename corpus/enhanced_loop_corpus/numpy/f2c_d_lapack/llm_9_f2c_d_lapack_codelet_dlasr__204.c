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
for (j = *n; j >= 2; --j) {
    ctemp = c__[j - 1];
    stemp = s[j - 1];
    if (ctemp == 1. && stemp == 0.) continue;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp = a[i__ + j * a_dim1];
        a[i__ + j * a_dim1] = ctemp * temp - stemp * a[i__ + a_dim1];
    }
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp = a[i__ + j * a_dim1];
        a[i__ + a_dim1] = stemp * temp + ctemp * a[i__ + a_dim1];
    }
}
}
