#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

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
for (j = 1; j <= i__1; j += 2) {
    if (j + 1 > i__1) break;
    ctemp = c__[j];
    stemp = s[j];
    doublereal ctemp2 = c__[j+1];
    doublereal stemp2 = s[j+1];
    if ((ctemp != 1. || stemp != 0.) && (ctemp2 != 1. || stemp2 != 0.)) {
        i__2 = *n;
        for (i__ = 1; i__ <= i__2; ++i__) {
            temp = a[j + 1 + i__ * a_dim1];
            doublereal temp2 = a[j + 2 + i__ * a_dim1];
            a[j + 1 + i__ * a_dim1] = ctemp * temp - stemp * a[j + i__ * a_dim1];
            a[j + i__ * a_dim1] = stemp * temp + ctemp * a[j + i__ * a_dim1];
            a[j + 2 + i__ * a_dim1] = ctemp2 * temp2 - stemp2 * a[j + 1 + i__ * a_dim1];
            a[j + 1 + i__ * a_dim1] = stemp2 * temp2 + ctemp2 * a[j + 1 + i__ * a_dim1];
        }
    }
}
}
