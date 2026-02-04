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
        i__1 = *n;
        for (i__ = 1; i__ <= i__1; ++i__) {
            doublereal *a_j_i     = &a[j + i__ * a_dim1];
            doublereal *a_j1_i    = &a[j + 1 + i__ * a_dim1];
            temp = *a_j1_i;
            doublereal new_val1 = ctemp * temp - stemp * (*a_j_i);
            doublereal new_val2 = stemp * temp + ctemp * (*a_j_i);
            *a_j1_i = new_val1;
            *a_j_i  = new_val2;
        }
    }
}
}
