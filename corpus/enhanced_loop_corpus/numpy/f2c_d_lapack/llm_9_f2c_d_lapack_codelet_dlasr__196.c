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
for (j = *m - 1; j >= 2; j -= 2) {
    integer j1 = j;
    integer j2 = j - 1;
    doublereal ctemp1 = c__[j1];
    doublereal stemp1 = s[j1];
    doublereal ctemp2 = c__[j2];
    doublereal stemp2 = s[j2];
    if ((ctemp1 != 1. || stemp1 != 0.) && (ctemp2 != 1. || stemp2 != 0.)) {
        i__1 = *n;
        for (i__ = 1; i__ <= i__1; ++i__) {
            temp = a[j1 + 1 + i__ * a_dim1];
            a[j1 + 1 + i__ * a_dim1] = ctemp1 * temp - stemp1 * a[j1 + i__ * a_dim1];
            a[j1 + i__ * a_dim1] = stemp1 * temp + ctemp1 * a[j1 + i__ * a_dim1];

            temp = a[j2 + 1 + i__ * a_dim1];
            a[j2 + 1 + i__ * a_dim1] = ctemp2 * temp - stemp2 * a[j2 + i__ * a_dim1];
            a[j2 + i__ * a_dim1] = stemp2 * temp + ctemp2 * a[j2 + i__ * a_dim1];
        }
    } else {
        i__1 = *n;
        for (i__ = 1; i__ <= i__1; ++i__) {
            if (ctemp1 != 1. || stemp1 != 0.) {
                temp = a[j1 + 1 + i__ * a_dim1];
                a[j1 + 1 + i__ * a_dim1] = ctemp1 * temp - stemp1 * a[j1 + i__ * a_dim1];
                a[j1 + i__ * a_dim1] = stemp1 * temp + ctemp1 * a[j1 + i__ * a_dim1];
            }
            if (ctemp2 != 1. || stemp2 != 0.) {
                temp = a[j2 + 1 + i__ * a_dim1];
                a[j2 + 1 + i__ * a_dim1] = ctemp2 * temp - stemp2 * a[j2 + i__ * a_dim1];
                a[j2 + i__ * a_dim1] = stemp2 * temp + ctemp2 * a[j2 + i__ * a_dim1];
            }
        }
    }
}
if (j == 1) {
    ctemp = c__[1];
    stemp = s[1];
    if (ctemp != 1. || stemp != 0.) {
        i__1 = *n;
        for (i__ = 1; i__ <= i__1; ++i__) {
            temp = a[2 + i__ * a_dim1];
            a[2 + i__ * a_dim1] = ctemp * temp - stemp * a[1 + i__ * a_dim1];
            a[1 + i__ * a_dim1] = stemp * temp + ctemp * a[1 + i__ * a_dim1];
        }
    }
}
}
