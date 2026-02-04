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
for (j = 2; j <= i__1; j += 2) {
    if (j + 1 > i__1) break;
    ctemp = c__[j - 1];
    stemp = s[j - 1];
    doublereal ctemp_next = c__[j];
    doublereal stemp_next = s[j];
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp = a[j + i__ * a_dim1];
        doublereal temp_next = a[j + 1 + i__ * a_dim1];
        doublereal a1_val = a[i__ * a_dim1 + 1];
        doublereal a2_val = a[i__ * a_dim1 + 2];

        a[j + i__ * a_dim1] = ctemp * temp - stemp * a1_val;
        a[i__ * a_dim1 + 1] = stemp * temp + ctemp * a1_val;

        a[j + 1 + i__ * a_dim1] = ctemp_next * temp_next - stemp_next * a2_val;
        a[i__ * a_dim1 + 2] = stemp_next * temp_next + ctemp_next * a2_val;
    }
}
}
