#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *c__;
extern real *s;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp;
extern real ctemp;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j <= i__1; ++j) {
    ctemp = c__[j - 1];
    stemp = s[j - 1];
    if (ctemp == 1.F && stemp == 0.F) {
        continue;
    }
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp = a[j + i__ * a_dim1];
        real a_val = a[i__ * a_dim1 + 1];
        a[j + i__ * a_dim1] = ctemp * temp - stemp * a_val;
        a[i__ * a_dim1 + 1] = stemp * temp + ctemp * a_val;
    }
}
}
