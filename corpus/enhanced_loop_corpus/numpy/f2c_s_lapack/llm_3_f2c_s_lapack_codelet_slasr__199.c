#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
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
for (j = 1; j <= i__1; ++j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1.F || stemp != 0.F) {
        i__2 = *n;
        integer stride = a_dim1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            integer base_idx = i__ * stride;
            temp = a[j + base_idx];
            a[j + base_idx] = stemp * a[*m + base_idx] + ctemp * temp;
            a[*m + base_idx] = ctemp * a[*m + base_idx] - stemp * temp;
        }
    }
}
}
