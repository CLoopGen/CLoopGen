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
            for (integer k = 0; k < 1; ++k) { // Introduce artificial nesting depth: add a trivial inner loop
                temp = a[i__ + (j + 1) * a_dim1];
                a[i__ + (j + 1) * a_dim1] = ctemp * temp - stemp * a[i__ + j * a_dim1];
                a[i__ + j * a_dim1] = stemp * temp + ctemp * a[i__ + j * a_dim1];
            }
        }
    }
}
}
