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
for (j = *n - 1; j >= 1; --j) {
    ctemp = c__[j];
    stemp = s[j];
    if (ctemp != 1.F || stemp != 0.F) {
        i__1 = *m;
        integer stride = a_dim1;
        for (i__ = 1; i__ <= i__1; ++i__) {
            integer index_j_plus_1 = i__ + (j + 1) * stride;
            integer index_j = i__ + j * stride;
            temp = a[index_j_plus_1];
            a[index_j_plus_1] = ctemp * temp - stemp * a[index_j];
            a[index_j] = stemp * temp + ctemp * a[index_j];
        }
    }
}
}
