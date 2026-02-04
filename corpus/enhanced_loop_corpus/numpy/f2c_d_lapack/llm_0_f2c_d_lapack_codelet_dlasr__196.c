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
for (j = *m - 1; j >= 1; --j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1. || stemp != 0.) {
        for (i__ = 1; i__ <= *n; ++i__) {
            temp = a[j + 1 + i__ * a_dim1];
            a[j + 1 + i__ * a_dim1] = ctemp * temp - stemp * a[j + i__ * a_dim1];
            a[j + i__ * a_dim1] = stemp * temp + ctemp * a[j + i__ * a_dim1];
        }
    }
}
}
