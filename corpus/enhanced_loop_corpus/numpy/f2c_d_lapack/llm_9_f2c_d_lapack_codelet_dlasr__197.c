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
for (j = 2; j <= i__1; ++j) {
    ctemp = c__[j - 1];
    stemp = s[j - 1];
    if (ctemp == 1. && stemp == 0.) continue;
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; i__ += 2) {
        if (i__ + 1 > i__2) {
            temp = a[j + i__ * a_dim1];
            a[j + i__ * a_dim1] = ctemp * temp - stemp * a[i__ * a_dim1 + 1];
            a[i__ * a_dim1 + 1] = stemp * temp + ctemp * a[i__ * a_dim1 + 1];
            break;
        }
        temp = a[j + i__ * a_dim1];
        doublereal temp2 = a[j + (i__ + 1) * a_dim1];
        doublereal a1_val = a[i__ * a_dim1 + 1];
        doublereal a2_val = a[(i__ + 1) * a_dim1 + 1];

        a[j + i__ * a_dim1] = ctemp * temp - stemp * a1_val;
        a[i__ * a_dim1 + 1] = stemp * temp + ctemp * a1_val;

        a[j + (i__ + 1) * a_dim1] = ctemp * temp2 - stemp * a2_val;
        a[(i__ + 1) * a_dim1 + 1] = stemp * temp2 + ctemp * a2_val;
    }
}
}
