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
extern integer i__;
extern integer j;
extern real temp;
extern real ctemp;
extern real stemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *m; j >= 2; --j) {
    ctemp = c__[j - 1];
    stemp = s[j - 1];
    if (ctemp != 1.F || stemp != 0.F) {
        i__1 = *n;
        integer stride = a_dim1;
        for (i__ = 1; i__ <= i__1; ++i__) {
            integer base_i = i__ * stride;
            temp = a[base_i + j];
            a[base_i + j] = ctemp * temp - stemp * a[base_i + 1];
            a[base_i + 1] = stemp * temp + ctemp * a[base_i + 1];
        }
    }
}
}
