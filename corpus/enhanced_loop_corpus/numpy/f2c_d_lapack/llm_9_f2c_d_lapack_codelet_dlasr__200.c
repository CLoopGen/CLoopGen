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
    ctemp = c__[j];
    stemp = s[j];
    doublereal ctemp_prev = c__[j-1];
    doublereal stemp_prev = s[j-1];
    if ((ctemp != 1. || stemp != 0.) || (ctemp_prev != 1. || stemp_prev != 0.)) {
        i__1 = *n;
        for (i__ = 1; i__ <= i__1; ++i__) {
            temp = a[j + i__ * a_dim1];
            a[j + i__ * a_dim1] = stemp * a[*m + i__ * a_dim1] + ctemp * temp;
            a[*m + i__ * a_dim1] = ctemp * a[*m + i__ * a_dim1] - stemp * temp;

            temp = a[j - 1 + i__ * a_dim1];
            a[j - 1 + i__ * a_dim1] = stemp_prev * a[*m + i__ * a_dim1] + ctemp_prev * temp;
            a[*m + i__ * a_dim1] = ctemp_prev * a[*m + i__ * a_dim1] - stemp_prev * temp;
        }
    }
}
if (*m - 1 >= 1 && ((*m - 1) % 2 == 0)) {
    j = 1;
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1. || stemp != 0.) {
        i__1 = *n;
        for (i__ = 1; i__ <= i__1; ++i__) {
            temp = a[j + i__ * a_dim1];
            a[j + i__ * a_dim1] = stemp * a[*m + i__ * a_dim1] + ctemp * temp;
            a[*m + i__ * a_dim1] = ctemp * a[*m + i__ * a_dim1] - stemp * temp;
        }
    }
}
}
