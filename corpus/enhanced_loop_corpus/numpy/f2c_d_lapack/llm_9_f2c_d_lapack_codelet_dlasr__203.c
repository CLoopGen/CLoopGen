#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
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
for (j = 2; j <= i__1; j += 2) {
    if (j + 1 > i__1) continue;
    ctemp = c__[j - 1];
    stemp = s[j - 1];
    doublereal ctemp_next = c__[j];
    doublereal stemp_next = s[j];
    if ((ctemp != 1. || stemp != 0.) || (ctemp_next != 1. || stemp_next != 0.)) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            temp = a[i__ + j * a_dim1];
            doublereal temp_next = a[i__ + (j + 1) * a_dim1];
            doublereal a_prev = a[i__ + a_dim1];
            doublereal a_prev_next = a[i__ + a_dim1];

            a[i__ + j * a_dim1] = ctemp * temp - stemp * a_prev;
            a[i__ + a_dim1] = stemp * temp + ctemp * a_prev;

            a[i__ + (j + 1) * a_dim1] = ctemp_next * temp_next - stemp_next * a_prev_next;
            a[i__ + a_dim1] = stemp_next * temp_next + ctemp_next * a_prev_next;
        }
    }
}
}
