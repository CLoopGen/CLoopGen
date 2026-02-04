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
    if (ctemp != 1. || stemp != 0.) {
        i__2 = *n;
        for (i__ = 1; i__ <= i__2; i__ += 2) {
            integer base_idx1 = i__ * a_dim1;
            integer base_idx2 = (i__ + 1) * a_dim1;
            temp = a[j + base_idx1];
            a[j + base_idx1] = ctemp * temp - stemp * a[base_idx1 + 1];
            a[base_idx1 + 1] = stemp * temp + ctemp * a[base_idx1 + 1];

            if (i__ + 1 <= i__2) {
                temp = a[j + base_idx2];
                a[j + base_idx2] = ctemp * temp - stemp * a[base_idx2 + 1];
                a[base_idx2 + 1] = stemp * temp + ctemp * a[base_idx2 + 1];
            }
        }
    }
}
}
