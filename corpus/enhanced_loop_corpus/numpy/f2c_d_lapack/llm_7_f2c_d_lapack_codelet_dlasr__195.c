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
doublereal temp_prev = 0.0;
for (j = 1; j <= i__1; ++j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1. || stemp != 0.) {
        i__2 = *n;
        for (i__ = 1; i__ <= i__2; ++i__) {
            temp = a[j + 1 + i__ * a_dim1];
            doublereal update1 = ctemp * temp - stemp * a[j + i__ * a_dim1];
            doublereal update2 = stemp * temp + ctemp * a[j + i__ * a_dim1];
            a[j + i__ * a_dim1] += update2 - a[j + i__ * a_dim1]; 
            a[j + 1 + i__ * a_dim1] = update1;
            temp_prev = temp;
        }
    } else {
        for (i__ = 1; i__ <= *n; ++i__) {
            temp_prev = a[j + 1 + i__ * a_dim1];
        }
    }
}
}
