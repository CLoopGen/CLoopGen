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
        i__2 = *n;
        for (i__ = 1; i__ <= i__2; ++i__) {
            integer idx_j = j + i__ * a_dim1;
            integer idx_m = *m + i__ * a_dim1;
            temp = a[idx_j];
            doublereal a_m_val = a[idx_m];
            a[idx_j] = stemp * a_m_val + ctemp * temp;
            a[idx_m] = ctemp * a_m_val - stemp * temp;
        }
    }
}
}
